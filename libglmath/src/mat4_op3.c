#include "../inc/mat4.h"

t_mat4 ft_quat_to_mat4( t_versor q ) {
	float w = q.q[0];
	float x = q.q[1];
	float y = q.q[2];
	float z = q.q[3];

    t_vec4  v[4];
    v[0] = ft_vec4_new(1.0f - 2.0f * y * y - 2.0f * z * z,
    2.0f * x * y + 2.0f * w * z, 2.0f * x * z - 2.0f * w * y, 0.0f);
    v[1] = ft_vec4_new(2.0f * x * y - 2.0f * w * z,
    1.0f - 2.0f * x * x - 2.0f * z * z, 2.0f * y * z + 2.0f * w * x, 0.0f);
    v[2] = ft_vec4_new(2.0f * x * z + 2.0f * w * y, 2.0f * y * z - 2.0f * w * x,
    1.0f - 2.0f * x * x - 2.0f * y * y, 0.0f);
    v[3] = ft_vec4_new(0.0f, 0.0f, 0.0f, 1.0f);
	return (ft_mat4_new( v[0], v[1], v[2], v[3]));
}

/*t_mat4 ft_mat4_look_at(t_vec3 cam_pos, t_vec3 targ_pos, t_vec3 up) {
	// inverse translation
	t_mat4 p = ft_mat4_identity();

	p = ft_mat4_translate( p, (t_vec3){{{-cam_pos.v[0], -cam_pos.v[1], -cam_pos.v[2]}}});
	//ft_mat4_print(p);
	//exit(0);
	// distance vector
	t_vec3 d = ft_vec3_sub(targ_pos , cam_pos);
	// forward vector
	t_vec3 f = ft_vec3_normalize(d);
	// right vector
	t_vec3 r = ft_vec3_normalize(ft_vec3_cross( f, up ) );
	// real up vector
	t_vec3 u = ft_vec3_normalize(ft_vec3_cross( r, f ) );
	t_mat4 ori = ft_mat4_identity();

	ori.m[0] = r.v[0];
	ori.m[4] = r.v[1];
	ori.m[8] = r.v[2];
	ori.m[1] = u.v[0];
	ori.m[5] = u.v[1];
	ori.m[9] = u.v[2];
	ori.m[2] = -f.v[0];
	ori.m[6] = -f.v[1];
	ori.m[10] = -f.v[2];
	return (ft_mat4_mult_mat4(ori,  p)); // p * ori;
}*/

t_mat4 ft_mat4_look_at(t_vec3 eye, t_vec3 target, t_vec3 upDir)
{
    // compute the forward vector from target to eye
    t_vec3 forward = ft_vec3_sub(eye, target);
    forward = ft_vec3_normalize(forward);                 // make unit length

    // compute the left vector
    t_vec3 left = ft_vec3_cross(upDir, forward); // cross product
    left = ft_vec3_normalize(left);

    // recompute the orthonormal up vector
    t_vec3 up = ft_vec3_cross(forward, left);    // cross product

    // init 4x4 matrix
    t_mat4 matrix;
    matrix = ft_mat4_identity();

    // set rotation part, inverse rotation matrix: M^-1 = M^T for Euclidean transform
    matrix.m[0] = left.x;
    matrix.m[4] = left.y;
    matrix.m[8] = left.z;
    matrix.m[1] = up.x;
    matrix.m[5] = up.y;
    matrix.m[9] = up.z;
    matrix.m[2] = forward.x;
    matrix.m[6] = forward.y;
    matrix.m[10]= forward.z;

    // set translation part
    matrix.m[12]= -left.x * eye.x - left.y * eye.y - left.z * eye.z;
    matrix.m[13]= -up.x * eye.x - up.y * eye.y - up.z * eye.z;
    matrix.m[14]= -forward.x * eye.x - forward.y * eye.y - forward.z * eye.z;
	
    return matrix;
}

t_mat4      ft_mat4_perspective(float fovy, float aspect, float near, float far)
{
    float fov_rad = DEG_TO_RAD(fovy);
	float inverse_range = 1.0f / tan( fov_rad / 2.0f );
	float sx = inverse_range / aspect;
	float sy = inverse_range;
	float sz = -( far + near ) / ( far - near );
	float pz = -( 2.0f * far * near ) / ( far - near );
	t_mat4 m = ft_mat4_zero(); // make sure bottom-right corner is zero
	m.m[0] = sx;
	m.m[5] = sy;
	m.m[10] = sz;
	m.m[14] = pz;
	m.m[11] = -1.0f;
    return m;   
}

t_mat4 ft_mat4_rotate(t_mat4 m, float angle, t_vec3 axis)
{
    axis = ft_vec3_normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;
    t_vec4 v[4];
	t_mat4	m_r;

	v[0] = ft_vec4_new(oc * axis.x * axis.x + c,
	oc * axis.x * axis.y - axis.z * s,
	oc * axis.z * axis.x + axis.y * s,  0.0);
	v[1] = ft_vec4_new(oc * axis.x * axis.y + axis.z * s,
	oc * axis.y * axis.y + c,
	oc * axis.y * axis.z - axis.x * s,  0.0);
	v[2] = ft_vec4_new(oc * axis.z * axis.x - axis.y * s,
	oc * axis.y * axis.z + axis.x * s,
	oc * axis.z * axis.z + c,0.0);
   m_r = ft_mat4_new(v[0], v[1], v[2], ft_vec4_new(0.0, 0.0, 0.0, 1.0));
   return (ft_mat4_mult_mat4(m_r, m));
}