Test Case - Test Fonts on Diagrams
==================================
:link_to_translation:`en:[English]`

blockdiag
---------

blockdiag - 示例 1
""""""""""""""""""

.. blockdiag::
    :scale: 75%
    :caption: 紧急处理程序流程图 (click to enlarge)
    :align: center
    
    blockdiag panic-handler {
        orientation = portrait;
        edge_layout = flowchart;
        default_group_color = white;

        cpu_exception [label = "CPU 异常", shape=roundedbox];
        sys_check [label = "Cache 错误,\nInterrupt WDT,\nabort()", shape=roundedbox];
        check_ocd [label = "JTAG 调试器\n已连接?", shape=diamond, width=160, height=80];
        print_error_cause [label = "打印出错原因"];
        use_jtag [label = "发送信号给 JTAG 调试器", shape=roundedbox];
        dump_registers [label = "Print registers\nand backtrace"];
        check_coredump [label = "使能 Core dump?", shape=diamond, width=160, height=80];
        do_coredump [label = "Core dump 到 UART 或者 Flash"];
        check_gdbstub [label = "使能 GDB Stub?", shape=diamond, width=160, height=80];
        do_gdbstub [label = "启动 GDB Stub", shape=roundedbox];
        halt [label = "暂停", shape=roundedbox];
        reboot [label = "重启", shape=roundedbox];
        check_halt [label = "暂停?", shape=diamond, width=160, height=80];

        group {cpu_exception, sys_check};

        cpu_exception -> print_error_cause;
        sys_check -> print_error_cause;
        print_error_cause -> check_ocd;
        check_ocd -> use_jtag [label = "Yes"];
        check_ocd -> dump_registers [label = "No"];
        dump_registers -> check_coredump
        check_coredump -> do_coredump [label = "Yes"];
        do_coredump -> check_gdbstub;
        check_coredump -> check_gdbstub [label = "No"];
        check_gdbstub -> check_halt [label = "No"];
        check_gdbstub -> do_gdbstub [label = "Yes"];
        check_halt -> halt [label = "Yes"];
        check_halt -> reboot [label = "No"];
    }



blockdiag - 示例 2
""""""""""""""""""

.. blockdiag::
    :caption: Wi-Fi 编程模型
    :align: center

    blockdiag wifi-programming-model {

        # global attributes
        node_height = 60;
        node_width = 100;
        span_width = 100;
        span_height = 60;
        default_shape = roundedbox;
        default_group_color = none;

        # node labels
        TCP_STACK [label="TCP\n 协议栈", fontsize=12];
        EVNT_TASK [label="Event\n 任务", fontsize=12];
        APPL_TASK [label="Application\n 任务", width = 120, fontsize=12];
        WIFI_DRV  [label="Wi-Fi\n 驱动", width = 120, fontsize=12];
        KNOT [shape=none];

        # node connections + labels
        TCP_STACK -> EVNT_TASK [label="事件"];
        EVNT_TASK -> APPL_TASK [label="回调\n 或事件"];

        # arrange nodes vertically
        group {
           label = "默认处理程序";
           orientation = portrait;
           EVNT_TASK <- WIFI_DRV [label="事件"];
        }

        # intermediate node
        group {
            label = "用户处理程序";
            orientation = portrait;
            APPL_TASK -- KNOT;
        }
        WIFI_DRV <- KNOT [label="API\n 调用"];
    }


blockdiag - 示例 3
""""""""""""""""""

.. blockdiag::
    :scale: 75%
    :caption: I2C 命令列表 - 以主机写为例 (click to enlarge)
    :align: center

    blockdiag i2c-command-link-master-write { 
        # global properties
        span_width = 5;
        span_height = 5;
        node_height = 25;
        default_group_color = lightgrey;
        class spacer [shape=none, width=10];
        class cmdlink [colwidth=2, width=180];
        class cjoint [shape=none, width=40];

        # all the rows
        0 -- a0 --                         f0 [style=none]; 
        1 -- a1 -- b1 -- c1 -- d1 -- e1 -- f1 -- g1 -- h1 [style=none]; 
        2 -- a2 -- b2 -- c2 -- d2 -- e2 -- f2 -- g2 [style=none]; 
        3 -- a3 --             d3 --       f3 [style=none];
        4 -- a4 [style=none];
        5 -- a5 [style=none];
        6 -- a6 --       c6 [style=none];
        7 -- a7 --       c7 -- d7 [style=none];
        8 -- a8 --       c8 --              f8 [style=none];
        9 -- a9 --       c9 --                         h9 [style=none];
        10 -- a10 [style=none];
        11 -- a11 [style=none];

        # separator row
        3, a3, d3, f3 [shape=none, height=5];

        # tuning node properties and connections
        0 [class=spacer]; a0 [shape=none, colwidth=5]; f0 [shape=note, colwidth=2];
        1 [class=spacer]; a1 [shape=none]; b1; c1 [width=40]; e1 [shape=none, width=30]; g1 [shape=none, width=30]; h1 [width=40];
        2 [class=spacer]; a2 [shape=none]; b2; c2 [class=cjoint]; d2 [shape=none]; e2 [width=30]; f2 [shape=none]; g2 [width=30];
        3 [class=spacer]; a3 [shape=none, colwidth=3]; d3 [colwidth=2]; f3 [colwidth=2];
        4 [class=spacer]; a4 [class=cmdlink]
        5 [class=spacer]; a5 [class=cmdlink];
        6 [class=spacer]; a6 [class=cmdlink]; c6 [class=cjoint]; a6 -- c6 [style=solid]; c6 -- c2 -> c1 [folded];
        7 [class=spacer]; a7 [class=cmdlink]; c7 [class=cjoint]; d7 [shape=none, colwidth=2]; a7 -- c7 -- d7 [style=solid]; d7 -> d3 [folded];
        8 [class=spacer]; a8 [class=cmdlink]; c8 [class=cjoint, colwidth=3]; f8 [shape=none, colwidth=2]; a8 -- c8 -- f8 [style=solid]; f8 -> f3 [folded];
        9 [class=spacer]; a9 [class=cmdlink]; c9 [class=cjoint, colwidth=5]; h9 [shape=none, width=40]; a9 -- c9 -- h9 [style=solid]; h9 -> h1 [folded];
        10 [class=spacer]; a10 [class=cmdlink]; 
        11 [class=spacer]; a11 [class=cmdlink]; 

        # labels
        f0 [label="连续发送 n 次数据", shape=note, color=yellow];
        b1 [label="主机", shape=note, color=lightyellow]; c1 [label="开始"]; d1 [label="从机地址"]; f1 [label="数据"]; h1 [label="停止"];
        b2 [label="从机", shape=note, color=lightyellow]; e2 [label="ACK"]; g2 [label="ACK"];  
        a4 [shape=note, label="命令", color=yellow]; 
        a5 [label="cmd = i2c_cmd_link_create()", numbered = 1]; 
        a6 [label="i2c_master_start(cmd)", numbered = 2]; 
        a7 [label="i2c_master_write_byte(cmd, Address, ACK)", numbered = 3]; 
        a8 [label="i2c_master_write(Data, n, ACK)", numbered = 4]; 
        a9 [label="i2c_master_stop(cmd)", numbered = 5]; 
        a10 [label="i2c_master_cmd_begin(I2c_port, cmd, wait)", numbered = 6]; 
        a11 [label="i2c_cmd_link_delete(cmd)", numbered = 7]; 

        # Slave Address
        group { d1; e1; }
        group { d2; e2; d3; }

        # Data x n times
        group { f1; g1;}
        group { f2; g2; f3; }
    }


seqdiag
-------

seqdiag - 示例 1
""""""""""""""""

.. seqdiag::
    :caption: 配网的一般流程
    :align: center

    seqdiag blufi {
        activation = none;
        node_width = 80;
        node_height = 60;
        edge_length = 380;
        span_height = 10;
        default_fontsize = 12; 

        Phone <- ESP32 [label="广播"];
        Phone -> ESP32 [label="建立 GATT 链接"];
        Phone <- ESP32 [label="协商密钥"];
        Phone -> ESP32 [label="协商密钥"];
        Phone -> ESP32 [label="CTRL: 设置 ESP32 手机安全模式"];
        Phone -> ESP32 [label="DATA: SSID"];
        Phone -> ESP32 [label="DATA: 密码"];
        Phone -> ESP32 [label="DATA: 其他信息，如 CA 认证"];
        Phone -> ESP32 [label="CTRL: 连接到 AP"];
        Phone <- ESP32 [label="DATA: 连接状态报告"];
    }


seqdiag - 示例 2
""""""""""""""""

.. seqdiag::
    :caption: 安全
    :align: center

    seqdiag security1 {
        activation = none;
        node_width = 80;
        node_height = 60;
        edge_length = 480;
        span_height = 5;
        default_shape = roundedbox;
        default_fontsize = 12;

        CLIENT  [label = "客户端"];
        DEVICE  [label = "设备"];

        === Security 1 ===
        CLIENT -> CLIENT [label = "生成密钥对", rightnote = "{cli_privkey, cli_pubkey} = curve25519_keygen()"];
        CLIENT -> DEVICE [label = "SessionCmd0(cli_pubkey)"];
        DEVICE -> DEVICE [label = "生成密钥对", leftnote = "{dev_privkey, dev_pubkey} = curve25519_keygen()"];
        DEVICE -> DEVICE [label = "Initialization\nVector", leftnote = "dev_rand = gen_16byte_random()"];
        DEVICE -> DEVICE [label = "共享密钥", leftnote = "shared_key(No PoP) = curve25519(dev_privkey, cli_pubkey) \nshared_key(with PoP) = curve25519(dev_privkey, cli_pubkey) ^ SHA256(pop)"];
        DEVICE -> CLIENT [label = "SessionResp0(dev_pubkey, dev_rand)"];
        CLIENT -> CLIENT [label = "共享密钥", rightnote = "shared_key(No PoP) = curve25519(cli_privkey, dev_pubkey)\nshared_key(with PoP) = curve25519(cli_privkey, dev_pubkey) ^ SHA256(pop)"];
        CLIENT -> CLIENT [label = "校验口令", rightnote = "cli_verify = aes_ctr_enc(key=shared_key, data=dev_pubkey, nonce=dev_rand)"];
        CLIENT -> DEVICE [label = "SessionCmd1(cli_verify)"];
        DEVICE -> DEVICE [label = "验证客户端", leftnote = "check (dev_pubkey == aes_ctr_dec(cli_verify...)"];
        DEVICE -> DEVICE [label = "校验口令", leftnote = "dev_verify = aes_ctr_enc(key=shared_key, data=cli_pubkey, nonce=(prev-context))"];
        DEVICE -> CLIENT [label = "SessionResp1(dev_verify)"];
        CLIENT -> CLIENT [label = "验证设备", rightnote = "check (cli_pubkey == aes_ctr_dec(dev_verify...)"];
    }


seqdiag - example 3
"""""""""""""""""""

 .. seqdiag::
    :caption: Wi-Fi 工作在 AP 模式下的示例
    :align: center

    seqdiag sample-scenarios-soft-ap-mode {
        activation = none;
        node_width = 80;
        node_height = 60;
        edge_length = 140;
        span_height = 5;
        default_shape = roundedbox;
        default_fontsize = 12; 

        MAIN_TASK  [label = "Main\n任务"]; 
        APP_TASK   [label = "App\n任务"];
        EVENT_TASK [label = "Event\n任务"];
        LwIP_TASK  [label = "LwIP\n任务"];
        WIFI_TASK  [label = "Wi-Fi\n任务"];

        === 1. 初始化阶段 ===
        MAIN_TASK  ->  LwIP_TASK   [label="1.1> 创建 / 初始化 LwIP"];
        MAIN_TASK  ->  EVENT_TASK  [label="1.2> 创建 / 初始化 event"];
        MAIN_TASK  ->  WIFI_TASK   [label="1.3> 创建 / 初始化 Wi-Fi"];
        MAIN_TASK  ->  APP_TASK    [label="1.4> 创建 app 任务"];
        === 2. 配置阶段 ===
        MAIN_TASK  ->  WIFI_TASK   [label="2> 配置 Wi-Fi"];
        === 3. 启动阶段 ===
        MAIN_TASK  ->  WIFI_TASK   [label="3.1> 启动 Wi-Fi"];
        EVENT_TASK <-  WIFI_TASK   [label="3.2> SYSTEM_EVENT_AP_START"];
        APP_TASK   <-  EVENT_TASK  [label="3.3> SYSTEM_EVENT_AP_START"];
        === 4. 连接阶段 ===
        EVENT_TASK <-  WIFI_TASK   [label="4.1> SYSTEM_EVENT_AP_STA_CONNECTED"];
        APP_TASK   <- EVENT_TASK   [label="4.2> SYSTEM_EVENT_AP_STA_CONNECTED"];
        === 5. 断开连接阶段 ===
        EVENT_TASK <-  WIFI_TASK   [label="5.1> SYSTEM_EVENT_STA_DISCONNECTED"];
        APP_TASK   <-  EVENT_TASK  [label="5.2> SYSTEM_EVENT_STA_DISCONNECTED"];
        APP_TASK   ->  APP_TASK    [label="5.3> 处理断开连接"];
        === 6. 去初始化阶段 ===
        APP_TASK   ->  WIFI_TASK   [label="6.1> 断开 Wi-Fi 连接"];
        APP_TASK   ->  WIFI_TASK   [label="6.2> 停止 Wi-Fi"];
        APP_TASK   ->  WIFI_TASK   [label="6.3> 去初始化 Wi-Fi"];
    }


packetdiag
----------

packetdiag - 示例 1
"""""""""""""""""""

.. packetdiag::
    :caption: NVS 页面结构
    :align: center

    packetdiag nvs_page_structure {
        colwidth = 32  
        node_width = 15
        node_height = 32
        default_fontsize = 12

        0-3: 状态\n(4)
        4-7: 序列号\n(4)
        8-27: 保留 (20)
        28-31: CRC32 校验值\n(4)
        32-63: 状态位映射 (32)  
        64-95: 条目 0 (32)
        96-127: 条目 1 (32)
        128-191: --- [colheight = 2]
        192-223: 条目 125 (32)
    }
