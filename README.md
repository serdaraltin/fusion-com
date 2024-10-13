# Fusion Bridge

**Fusion Bridge** is a middleware designed to facilitate data abstraction and communication between various technologies. It serves as a bridge, allowing information processed by one system to be seamlessly transferred to another. For example, it processes data captured from vision sensors (like Kinect2) and sends the interpreted results to another platform such as Unreal Engine for further use. This project is still in the early stages, focusing on network communication modules, with plans for expanding its capabilities in the future.

## Project Overview

- **Vision System**: Gathers data from sensors like Kinect2, processing it into actionable information.
- **Bridge**: Transfers the processed data between different technologies, acting as an abstraction layer.
    - For example, Kinect2 sends data to the `Vision` module for interpretation. `Bridge` then forwards this interpreted information to an external platform (e.g., Unreal Engine).

### Current Status

At present, the `Fusion Bridge` project contains an initial implementation of the network module, which enables message reception through UDP communication. The network module is designed with future scalability in mind and can be extended to support other communication protocols.

## Features

### Completed
- **Network Module**: Partial implementation of the network server for receiving UDP messages.
    - Messages are sent to the bridge for further processing.
    - Debug mode enabled for detailed message logging.

### In Progress / Planned
- **Message Abstraction**: Future versions will support abstracted communication between different data formats and technologies.
- **Sensor Integration**: Planned integration with various sensors (e.g., Kinect2, LIDAR).
- **Engine Compatibility**: Planned support for Unreal Engine, Unity, and other game engines for real-time simulation or rendering.
- **Middleware Design**: Extensible architecture for connecting various data sources and consumers.

## Installation

This project uses C++ and `Poco` for networking. To get started, you'll need to install the necessary dependencies.

### Prerequisites

- C++11 or higher
- [Poco C++ Libraries](https://pocoproject.org/)
- CMake 3.5 or higher

### Build Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/fusion-bridge.git
   ```

2. Navigate to the project directory and create a build folder:

   ```bash
   cd fusion-bridge
   mkdir build && cd build
   ```

3. Run CMake to configure the project:

   ```bash
   cmake ..
   ```

4. Build the project:

   ```bash
   make
   ```

## Usage

Once built, the current implementation of the `Fusion Bridge` can be run to receive UDP messages. The server listens on a specified port and prints incoming messages.

To run the server:

```bash
./fusion_bridge
```

By default, the server will:

- Listen on `0.0.0.0:5454`.
- Buffer up to 1024 bytes per message.
- Output received messages and sender information if debug mode is enabled.

## Example

An example of how the server is initialized and used:

```cpp
#include <iostream>
#include <thread>
#include <string>
#include "network/server.h"

using namespace bridge;

int main() {
    int port = 5454;
    int bufferSize = 1024;

    Server server(port, bufferSize);
    server.setDebugMode(true);  // Enable detailed logging

    RunnableAdapter<Server> serverRunnable(server, &Server::receiveMessages);
    Thread serverThread;

    serverThread.start(serverRunnable);
    serverThread.join();

    return 0;
}
```

The server listens for incoming UDP messages and prints them to the console.

## Future Enhancements

1. **Expanded Network Protocol Support**: Integration with additional networking protocols (e.g., TCP).
2. **Cross-Platform Compatibility**: Ensure the bridge works smoothly across different operating systems and environments.
3. **Inter-Technology Communication**: Establish full communication flow between various technologies like Unreal Engine, ROS, and other systems.
4. **Data Transformation Layer**: Add support for transforming and abstracting data between incompatible formats.
5. **Plugin Architecture**: Build a modular, plugin-based system to integrate new sensors and technologies with minimal changes to the core system.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.