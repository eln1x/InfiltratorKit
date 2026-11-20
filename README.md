# Infiltrator Kit

Infiltrator Kit is a collection of Windows C++ proof-of-concept projects that
demonstrate security-sensitive process and access-token techniques. The code is
provided for authorized security research and defensive analysis.

## Projects

| Project | Overview |
| --- | --- |
| `TokenThief+` | Demonstrates named-pipe-based access-token impersonation. |
| `ExecShellCode+` | Demonstrates transferring execution to a memory-resident payload. |
| `ShellCodeThread+` | Demonstrates remote-thread-based execution of a memory-resident payload. |

These techniques can be used to compromise systems. This repository is not a
general-purpose software package, and its contents should not be run on systems
you do not own or have explicit permission to assess.

## Safety and scope

- Use only in an isolated lab or during a formally authorized assessment.
- Do not use the code to access accounts, processes, or systems without
  authorization.
- Review and understand the source before handling it; do not treat these
  proof-of-concepts as safe or production-ready.
- This repository is for research and defensive analysis, not a deployment
  guide. It does not provide build or execution instructions.

