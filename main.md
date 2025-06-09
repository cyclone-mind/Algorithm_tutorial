graph TD
    A[用户态] -->|系统调用| B[内核态]
    B -->|中断| A
    B -->|异常| A
    B -->|系统调用返回| A
    
    subgraph 系统调用示例
    C[文件操作] --> D[read/write]
    E[进程管理] --> F[fork/exec]
    G[网络通信] --> H[socket]
    end
    
    subgraph 中断示例
    I[硬件中断] --> J[时钟中断]
    K[外设中断] --> L[键盘/鼠标]
    end
    
    subgraph 异常示例
    M[除零错误] --> N[页错误]
    O[非法指令] --> P[越界访问]
    end
