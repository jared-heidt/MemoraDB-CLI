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
| `update` | Update one key-value pair | Key |  |
| `delete` | Delete one key-value pair | Key |  |
| `upsert` | If the key does not exist, create key-value pair. If the key already exists, update the value for the existing pair. | Key | Value |

### Examples
Create the key value pair (challenger, 1)
```bash
$ ./memora -c challenger 1
```

Read the key value pair with key challenger
```bash
$ ./memora -r challenger
```

Update the key value pair with key challenger
Create the key value pair (challenger, 1)
```bash
$ ./memora -u challenger 14
```

Delete the key value pair with key challenger
Create the key value pair (challenger, 1)
```bash
$ ./memora -d challenger
```

## References
- https://github.com/dmulholl/kash/tree/master
- https://clig.dev/#the-basics