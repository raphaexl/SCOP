# include "../incs/scop.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../incs/stb_image.h"

GLuint  ft_make_mesh_vertices_vbo(t_obj *obj)
{
    GLuint  vbo;
    float   *vertices;
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    int size = obj->vertices.size(&obj->vertices) * sizeof(t_vec3);
    vertices = malloc( obj->vertices.size(&obj->vertices) * 3 * sizeof(float));
    for (int i = 0; i < obj->vertices.size(&obj->vertices); i++)
    {
        t_vec3 *vec = (t_vec3 *)obj->vertices.items[i];
        int k = i * 3;
        vertices[k + 0] = vec->x;
        vertices[k + 1] = vec->y;
        vertices[k + 2] = vec->z;
    }
    
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    return (vbo);
}

GLuint  ft_make_mesh_colors_vbo(t_obj *obj)
{
    GLuint  vbo;
    float   *colors;
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    int size = obj->colors.size(&obj->colors) * sizeof(t_vec3);
    colors = malloc( obj->colors.size(&obj->colors) * 3 * sizeof(float));
    for (int i = 0; i < obj->colors.size(&obj->colors); i++)
    {
        t_vec3 *vec = (t_vec3 *)obj->colors.items[i];
        int k = i * 3;
        colors[k + 0] = vec->x;
        colors[k + 1] = vec->y;
        colors[k + 2] = vec->z;
    }
    
    glBufferData(GL_ARRAY_BUFFER, size, colors, GL_STATIC_DRAW);
    return (vbo);
}

GLuint  ft_make_mesh_normals_vbo(t_obj *obj)
{
    GLuint  vbo;
    float   *normals;
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    int size = obj->normals.size(&obj->normals) * sizeof(t_vec3);
    normals = malloc( obj->normals.size(&obj->normals) * 3 * sizeof(float));
    for (int i = 0; i < obj->normals.size(&obj->normals); i++)
    {
        t_vec3 *vec = (t_vec3 *)obj->normals.items[i];
        int k = i * 3;
        normals[k + 0] = vec->x;
        normals[k + 1] = vec->y;
        normals[k + 2] = vec->z;
    }
    
    glBufferData(GL_ARRAY_BUFFER, size, normals, GL_STATIC_DRAW);
    return (vbo);
}

GLuint  ft_make_mesh_uvs_vbo(t_obj *obj)
{
    GLuint  vbo;
    float   *uvs;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    int size = obj->vertices.size(&obj->uvs) * sizeof(t_vec2);
    uvs = malloc( obj->uvs.size(&obj->uvs) * 2 * sizeof(float));
    for (int i = 0; i < obj->uvs.size(&obj->uvs); i++)
    {
        t_vec2 *vec = (t_vec2 *)obj->uvs.items[i];
        int k = i * 2;
        uvs[k + 0] = vec->x;
        uvs[k + 1] = vec->y;
    }
    glBufferData(GL_ARRAY_BUFFER, size, uvs, GL_STATIC_DRAW);
    return (vbo);
}

GLuint  ft_make_mesh_texture(const char *texture_name, int *has_texture){
    GLuint texture = 0;

    glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load(texture_name, &width, &height, &nrChannels, 0);
    if (data)
    {
        if (nrChannels == 4){
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }else if (nrChannels == 3){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }else{
            printf("Texture not loaded ..... NB Channels: %d \n", nrChannels);
            *has_texture = 0;
            printf("Failed to load texture");
        }
        glGenerateMipmap(GL_TEXTURE_2D);
        *has_texture = 1;
    }
    else
    {
        printf("Failed to load texture");
        *has_texture = 0;
    }
    stbi_image_free(data);
    return texture;
}



t_mat4 mouseRot;
t_mat4 mouseTrans;
double deltaT;
double theta, phi;
double moveX, moveY;

float lastX = 400, lastY = 400;
float  AMORTIZATION = 0.90;
int firstMouse = 1;
int dragging = 0;
float dX = 0, dY = 0;

void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos){

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) != GLFW_PRESS &&
    glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) != GLFW_PRESS)
    {
      dragging = 0;
      lastX = xpos;
      lastY = ypos;
      return;
    }

    dragging = 1;
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = 0;
    }
  
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    dX = xoffset;
    dY = yoffset;

     if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) 
     {
        theta += dX;
        phi += dY;
    }else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS){
        moveX += dX;
        moveY += dY;
    }
}

#define DISPLAY_FILLED 0
#define DISPLAY_WIREFRAME 1
#define DISPLAY_POINTS 2

#define OBJECT_DISPLAY_COLOR 0
#define OBJECT_DISPLAY_TEXTURE 1

void    ft_process_scop_input(GLFWwindow *win, float *c_trans_timer, int *display, float delta)
{
    static int next_display = OBJECT_DISPLAY_COLOR;
    static int stop_timer = 1;
    static int timer_running = 0;
    
    if (*c_trans_timer >= 1 && !stop_timer){
        *c_trans_timer = 1;
        stop_timer = 1;
        timer_running = 0;
    }else if (*c_trans_timer < 0){
        *c_trans_timer = 0;
         stop_timer = 1;
        timer_running = 0;
    }
    if (glfwGetKey(win, GLFW_KEY_T) == GLFW_PRESS)
    {
        if (!timer_running){
            next_display = next_display == OBJECT_DISPLAY_TEXTURE ? OBJECT_DISPLAY_COLOR : OBJECT_DISPLAY_TEXTURE;
            stop_timer = 0;
        }
    }else if (glfwGetKey(win, GLFW_KEY_SPACE) == GLFW_PRESS && next_display != *display){
        *display = (*display + 1) % (DISPLAY_POINTS + 1);
        next_display = (*display + 1) % (DISPLAY_POINTS + 1);
    }
    if (!stop_timer){
        if (next_display == OBJECT_DISPLAY_COLOR){
            *c_trans_timer -= delta;
        }else{
            *c_trans_timer += delta;
        }
        timer_running = 1;
    }
}

void    ft_run(t_obj *obj)
{
    GLFWwindow  *win;
    t_shader    shader;    
    GLuint  vao, v_vbo, c_vbo, uv_vbo, n_vbo;
    GLuint  texture_id;
    t_camera    cam;
    static  double  last_time;
    float          color_timer = 0;
    int         current_display = 0;
    
    deltaT = 0;
    mouseRot = ft_mat4_identity();
    if (!(win = ft_opengl_window()))
    return ;
    glfwSetCursorPosCallback(win, mouse_cursor_callback);
    shader = ft_shader_init("commons/vertex_shader.glsl", "commons/fragment_shader.glsl");
    cam = ft_camera();
    if (obj->texture_file_name){
        texture_id = ft_make_mesh_texture(obj->texture_file_name, &obj->has_texture);
       if (obj->has_texture == 0){
       glDeleteTextures(1, &texture_id);
       ft_shader_clear(&shader);
       ft_opengl_clear(&win);
       return ;
       }
    }
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    v_vbo = ft_make_mesh_vertices_vbo(obj);
    c_vbo = ft_make_mesh_colors_vbo(obj);
    uv_vbo = ft_make_mesh_uvs_vbo(obj);
    n_vbo = ft_make_mesh_normals_vbo(obj);
    if (obj->has_vertices){
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, v_vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, c_vbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    }else{
        if (obj->has_texture == 0){
            glDeleteTextures(1, &texture_id);
        }
        ft_shader_clear(&shader);
        ft_opengl_clear(&win);
        ft_putendl("Couldn't load the obj file");
        return ;
    }
    if (obj->has_uvs){
        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, uv_vbo);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    }
   if (obj->has_normals){
        glEnableVertexAttribArray(3);
        glBindBuffer(GL_ARRAY_BUFFER, n_vbo);
        glVertexAttribPointer(3, 3,  GL_FLOAT,  GL_FALSE, 0, (void*)0);
    }
    ft_opengl_print();
    last_time = glfwGetTime();

    while (!glfwWindowShouldClose(win))
    {
        ft_opengl_fps(win);
        deltaT = (glfwGetTime() - last_time);
        ft_process_input(win, &cam, (float)deltaT);
        ft_process_scop_input(win, &color_timer, &current_display, deltaT);
        last_time = glfwGetTime();
        glClearColor(0.2, 0.3, 0.4, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ft_shader_use(&shader);
        if (obj->has_texture){
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture_id);
            ft_shader_set_int(&shader, "CC_Texture0", 0);
        }
        ft_shader_set_float(&shader, "time", (float)glfwGetTime());
        ft_shader_set_float(&shader, "c_time", color_timer);
        ft_shader_set_mat4f(&shader, "projection", cam.projection);
        ft_shader_set_mat4f(&shader, "view", cam.view);
        t_mat4 model = ft_mat4_identity();
        t_mat4 defaultMat = ft_mat4_identity();
        defaultMat = ft_mat4_translate(defaultMat, obj->offset);//Save the center vector
        model = ft_mat4_mult_mat4(defaultMat, model);

        model = ft_mat4_rotate(model,  glfwGetTime(), ft_vec3_new(0.0, 1.0, 0.0));
       if (!dragging){
            dX *= AMORTIZATION;
            dY *= AMORTIZATION;
            theta += dX;
            phi += dY;
        }
        mouseRot = ft_mat4_identity();
        mouseRot = ft_mat4_rotate_y_deg(mouseRot, theta);
        mouseRot = ft_mat4_rotate_x_deg(mouseRot, -phi);
        mouseTrans = ft_mat4_identity();
        mouseTrans = ft_mat4_translate(mouseTrans, ft_vec3_new(moveX * 0.01, moveY * 0.01, 0.0));
        model = ft_mat4_mult_mat4(mouseRot, model);
        model = ft_mat4_mult_mat4(mouseTrans, model);
        ft_shader_set_mat4f(&shader, "model", model);
        glBindVertexArray(vao);
        if (current_display == DISPLAY_FILLED){
            glDrawArrays(GL_TRIANGLES, 0, obj->vertices.length);
        }else if (current_display == DISPLAY_WIREFRAME){
            glDrawArrays(GL_LINES, 0, obj->vertices.length);
        }else if (current_display == DISPLAY_POINTS){
            glDrawArrays(GL_POINTS, 0, obj->vertices.length);
        }else{
            ft_putendl("Unknown display mode request :-( !");
        }
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    if (obj->has_vertices){
            glDeleteBuffers(1, &c_vbo);
            glDeleteBuffers(1, &v_vbo);
    }
    if (obj->has_uvs){
        glDeleteBuffers(1, &uv_vbo);
    }
    if (obj->has_normals){
        glDeleteBuffers(1, &n_vbo);
    }
    if (obj->has_texture){
       glDeleteTextures(1, &texture_id);
    }
    glDeleteVertexArrays(1, &vao);
    ft_shader_clear(&shader);
    ft_opengl_clear(&win);
}