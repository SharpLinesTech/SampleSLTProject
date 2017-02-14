in vec3 vertex;
in vec3 normal;

out vec3 out_normal;

void main() {
  vec4 ws_vertex = object_to_world * vec4(vertex, 1.0);
  vec4 ws_normal = object_to_world * vec4(normal, 0.0);

  out_normal = (world_to_camera * ws_normal).xyz;

  gl_Position = world_to_screen * ws_vertex;
}