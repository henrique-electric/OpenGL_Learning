#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void) {
// Initialize the library
	if (!glfwInit())
		return -1;
	// Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	// Make the window's context current
	glfwMakeContextCurrent(window);
	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}