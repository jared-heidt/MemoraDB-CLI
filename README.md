# MemoraDB Command Line Interface
## User Commands
### Name
memora - manage key-value pairs in connected MemoraDB

### Usage
memora [COMMAND] [FIRST PARAMETER] [SECOND PARAMETER]

### Commands 
| Command | Description | First Parameter | Second Parameter |
| --- | --- | --- | --- |
| `connect` | Connect to MemoraDB | Address | Port |
| `connect` | Close current MemoraDB connection |  |  |
| `exit` | Exit the CLI |  |  |
| `create` | Create one key-value pair | Key | Value |
| `read` | Read one key-value pair | Key |  |
| `update` | Update one key-value pair | Key | Value |
| `delete` | Delete one key-value pair | Key |  |
| `upsert` | If the key does not exist, create key-value pair. If the key already exists, update the value for the existing pair. | Key | Value |
| `help` | List builtin commands |  |  |

### Examples
Connect to MemoraDB running at 127.0.0.1:3434
```
> connect 127.0.0.1 3434
```

Insert key-value pair of color, orange
```
> create color orange
```

Read key-value pair with key color
```
> read color
color orange
```

Close current MemoraDB connection 
```
> close
```

Exit MemoraDB CLI
```
> exit
```

## References
- https://github.com/dmulholl/kash/tree/master
- https://clig.dev/#the-basics