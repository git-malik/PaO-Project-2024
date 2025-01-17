# SenseNet

SenseNet is a graphical interface software designed for managing and monitoring network sensors. The program is intended to monitor connections between hosts within a specific static and immutable network through dedicated sensors.

## Features

### Core Features
- Create, modify and remove different types of sensors (5 different types)
- Search for sensors within the current connection using RegEx
- Data persistence through JSON save files
- Real-time monitoring and visualization of network metrics
- Multiple measurement visualization through dedicated graphs

### Sensor Types
1. **Bandwidth Sensor**: Measures bandwidth usage (in Mbps) with maximum sensitivity of 1 Gbps per measurement
2. **Error Sensor**: Measures total errors (packet loss, collisions, etc.) with maximum sensitivity of 500 errors per measurement
3. **Load Sensor**: Shows connection occupancy (in %) relative to its maximum load capacity
4. **Delay Sensor**: Displays response time (in ms) with measurements up to 1000 ms
5. **Jitter Sensor**: Measures connection stability variations (in ms) with maximum sensitivity of 50 ms per measurement

### File Operations
- **Save**: Overwrites the existing JSON file if previously exported/saved
- **Export JSON**: Saves configurations to a JSON file with custom path and filename
- **Import JSON**: Loads previously saved sensor configurations (JSON format only)

### Keyboard Shortcuts
- **CTRL+S** (CMD+S on MacOS): Save
- **CTRL+E** (CMD+E on MacOS): Export JSON
- **CTRL+I** (CMD+I on MacOS): Import JSON
- **CTRL+N** (CMD+N on MacOS): Add new sensor

## Technical Details

### Data Persistence
- Configurations are saved in JSON format
- Each saved element contains:
  - Connection name
  - Associated sensors (ID and name)
- Invalid configurations or mismatched sensor types are ignored during import

### Core Components
- Abstract classes for Sensors and Packets
- Host and Connection classes identified by name
- Implementation of non-trivial polymorphism through Visitor Design Pattern
- MVC architecture

## Compilation Instructions (Ubuntu)

In the directory containing `SenseNetCPPro.pro`, execute:
```bash
qmake SenseNetCPPro.pro && make && ./SenseNetCPPro
```

## Design Patterns
- Visitor Pattern for sensor type validation and graph simulation
- MVC architecture for separation of concerns

## Requirements
- Qt Framework
- C++ compiler
- JSON support

## Notes
- Only one sensor of each type can be added per connection
- Sensor IDs are unique and immutable
- Sensor names can be modified through the GUI
- Host and connection names are defined within the program and cannot be modified

## Project Contributors
- Alessandro Di Pasquale - 2075544
- Malik Giafar Mohamed - 2075543

Academic Year: 2023/2024
