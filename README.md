# OpenGL Image Processing

A real-time image processing application built with OpenGL that demonstrates advanced shader-based color manipulation techniques. This application features YUV color space transformation, texture blending, and interactive controls for real-time image processing effects.

## Features

- **YUV Color Space Manipulation**: Adjust Y (luminance), U, and V (chrominance) channels independently
- **Dual Texture Blending**: Blend two textures with 50% mixing for creative effects
- **Color Inversion**: Toggle color inversion for negative image effects
- **Real-time Processing**: All effects are processed in real-time using GPU shaders
- **Interactive GUI**: Tool window with sliders for adjusting processing parameters on-the-fly
- **Perspective Camera**: Built-in camera system for 3D rendering capabilities

## Screenshots

The application displays a quad with blended textures (Wood and Emoji) that can be manipulated through the control window.

## Technology Stack

- **Graphics API**: OpenGL 3.3+
- **Language**: C++ with C++/CLI for GUI components
- **Dependencies**:
  - GLEW 2.1.0 (OpenGL Extension Wrangler)
  - GLFW 3.3.4 (Window and input management)
  - GLM (OpenGL Mathematics)
  - STB (Image loading)
- **Build System**: Visual Studio 2017+ (MSBuild)

## Requirements

### System Requirements
- Windows operating system
- Graphics card with OpenGL 3.3+ support
- Visual Studio 2017 or later

### Build Requirements
- Microsoft Visual Studio 2017 or later
- Windows SDK
- .NET Framework (for GUI components)

## Building the Project

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Dryader/OpenGL-Image-Processing.git
   cd OpenGL-Image-Processing
   ```

2. **Open the solution**:
   - Open `Midterm.sln` in Visual Studio

3. **Build the project**:
   - Select your desired configuration (Debug/Release) and platform (x86/x64)
   - Build → Build Solution (or press `Ctrl+Shift+B`)

4. **Run the application**:
   - Press `F5` to run with debugging or `Ctrl+F5` to run without debugging

## Project Structure

```
OpenGL-Image-Processing/
├── Midterm/                    # Main project directory
│   ├── Assets/
│   │   └── Textures/          # Texture files (Wood.jpg, Emoji.jpg)
│   ├── Shaders/               # GLSL shader files
│   │   ├── SimpleVertexShader.vertexshader.txt
│   │   └── SimpleFragmentShader.fragmentshader.txt
│   ├── Camera.cpp/h           # Camera implementation
│   ├── GameController.cpp/h   # Main game loop and initialization
│   ├── Mesh.cpp/h             # Mesh rendering
│   ├── Shader.cpp/h           # Shader management
│   ├── Texture.cpp/h          # Texture loading and management
│   ├── ToolWindow.cpp/h       # GUI control window
│   ├── WindowController.cpp/h # Window management
│   └── main.cpp               # Application entry point
├── External/                  # Third-party libraries
│   ├── glew-2.1.0/
│   ├── glfw-3.3.4/
│   ├── glm/
│   └── stb/
└── Midterm.sln               # Visual Studio solution file
```

## Usage

1. **Launch the application**: Run the executable from Visual Studio or the build output directory
2. **Control Window**: A tool window will appear with the following controls:
   - **Y Scale**: Adjust luminance (brightness) - Range: 0-200%
   - **U Scale**: Adjust chrominance U channel - Range: 0-200%
   - **V Scale**: Adjust chrominance V channel - Range: 0-200%
   - **Invert Colors**: Toggle to invert the final RGB output
3. **Main Window**: Displays the processed image with real-time updates as you adjust the controls

## How It Works

### Color Space Conversion
The application converts RGB colors to YUV color space for manipulation:
- **Y (Luminance)**: Represents brightness
- **U and V (Chrominance)**: Represent color information

After manipulation, the colors are converted back to RGB for display.

### Shader Pipeline
1. **Vertex Shader**: Passes vertex positions, colors, and texture coordinates to the fragment shader
2. **Fragment Shader**:
   - Samples two textures and blends them 50/50
   - Converts RGB to YUV color space
   - Applies scaling factors to Y, U, and V channels
   - Converts back to RGB
   - Optionally inverts colors
   - Outputs final color

## Keyboard Controls

- **ESC**: Exit the application (when implemented)

## Customization

### Adding New Textures
1. Place your image files in `Midterm/Assets/Textures/`
2. Update the texture loading code in `Mesh.cpp`:
   ```cpp
   m_texture.LoadTexture("Assets/Textures/YourTexture.jpg");
   ```

### Modifying Shaders
Edit the shader files in `Midterm/Shaders/` to create custom image processing effects.

## License

This project is available for educational purposes.

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## Acknowledgments

- OpenGL community for excellent documentation and resources
- GLEW, GLFW, GLM, and STB library maintainers
