Test Case - Generation of Diagrams
==================================

Evaluation of `blockdiag - simple diagram images generator <http://blockdiag.com/en/index.html>`_


blockdiag examples
^^^^^^^^^^^^^^^^^^

http://blockdiag.com/en/blockdiag/index.html


blockdiag - example 1
"""""""""""""""""""""

**Current implementation with ASCII art**

::

    +--------+     +--------+     +--------+     +--------+
    | Page 1 |     | Page 2 |     | Page 3 |     | Page 4 |
    | Full   +---> | Full   +---> | Active |     | Empty  |   <- states
    | #11    |     | #12    |     | #14    |     |        |   <- sequence numbers
    +---+----+     +----+---+     +----+---+     +---+----+
        |               |              |             |
        |               |              |             |
        |               |              |             |
    +---v------+  +-----v----+  +------v---+  +------v---+
    | Sector 3 |  | Sector 0 |  | Sector 2 |  | Sector 1 |    <- physical sectors
    +----------+  +----------+  +----------+  +----------+

**New implementation**

.. blockdiag::

    blockdiag sector_to_pages_mapping {

        default_group_color = "#f2f2f2";
        span_width = 30;

        P1 [label = "Page 1\nFull\n#11", height=60, width=60];
        P2 [label = "Page 2\nFull\n#12", height=60, width=60];
        P3 [label = "Page 3\nActive\n#13", height=60, width=60];
        P4 [label = "Page 4\nEmpty\n#", height=60, width=60];
        PN [label = "<- page #\n<- states\n<- sequence #", height=60, width=160, shape=note, color=yellow];

        S3 [label = "Sector 3", width=80];
        S0 [label = "Sector 0", width=80];
        S2 [label = "Sector 2", width=80];
        S1 [label = "Sector 1", width=80];
        SN [label = "<- physical sectors", width=160, shape=note, color=yellow];

        P1 -> P2;
        P2 -> P3;
        P3 -> P4 [style = dashed];
        P4 -> PN [style = none];

        group {
           orientation = portrait
           P1 -> S3;
        }
        group {
           orientation = portrait
           P2 -> S0;
        }
        group {
           orientation = portrait
           P3 -> S2;
        }
        group {
           orientation = portrait
           P4 -> S1;
        }
        group {
           orientation = portrait
           PN -> SN [style = none];
        }
    }


**Code of the new implementation**

::

    blockdiag sector_to_pages_mapping {

        default_group_color = "#f2f2f2";
        span_width = 30;

        P1 [label = "Page 1\nFull\n#11", height=60, width=60];
        P2 [label = "Page 2\nFull\n#12", height=60, width=60];
        P3 [label = "Page 3\nActive\n#13", height=60, width=60];
        P4 [label = "Page 4\nEmpty\n#", height=60, width=60];
        PN [label = "<- page #\n<- states\n<- sequence #", height=60, width=160, shape=note, color=yellow];

        S3 [label = "Sector 3", width=80];
        S0 [label = "Sector 0", width=80];
        S2 [label = "Sector 2", width=80];
        S1 [label = "Sector 1", width=80];
        SN [label = "<- physical sectors", width=160, shape=note, color=yellow];

        P1 -> P2;
        P2 -> P3;
        P3 -> P4 [style = dashed];
        P4 -> PN [style = none];

        group {
           orientation = portrait
           P1 -> S3;
        }
        group {
           orientation = portrait
           P2 -> S0;
        }
        group {
           orientation = portrait
           P3 -> S2;
        }
        group {
           orientation = portrait
           P4 -> S1;
        }
        group {
           orientation = portrait
           PN -> SN [style = none];
        }
    }


blockdiag - example 2
"""""""""""""""""""""

**Current implementation with ASCII art**

::

                            default handler              user handler
   -----------               -------------               -------------
  |           |   event     |             | callback or |             |
  |   TCPIP   | --------->  |    event    | ----------> | application |
  |   stack   |             |     task    |  event      |    task     |
   -----------               -------------               -------------
                                  /|\                          |
                                   |                           |
                            event  |                           |
                                   |                           |
                                   |                           |
                              -------------                    |
                             |             |                   |
                             | Wi-Fi Driver|/__________________|
                             |             |\     API call
                             |             |
                              -------------


**New implementation**

.. blockdiag::

    blockdiag sector_to_pages_mapping {

        node_width = 120; 
        node_height = 60;

        span_height = 60;
        span_width = 100;

        default_shape = roundedbox;

        default_group_color = none;
        default_fontsize = 14

        TCP_STACK [label = "TCP\n stack"];  
        EVNT_TASK [label = "event\n task"];  
        APPL_TASK [label = "application\n task", width=130];  
        WIFI_DRV  [label = "Wi-Fi\n Driver"];  
        SPACER [label = "", shape = none, width=1, height=1];

        TCP_STACK -> EVNT_TASK [label = "event", fontsize = 12];
        EVNT_TASK -> APPL_TASK [label = "callback\n or event", fontsize = 12];

        group {
           label = "default handler";
           fontsize = 12
           orientation = portrait;
           EVNT_TASK <- WIFI_DRV [label = "event", fontsize = 12];
        }

        group {
            label = "user handler";
            fontsize = 12
            orientation = portrait;
            APPL_TASK -- SPACER;
        }
        WIFI_DRV <- SPACER [label = "API\n call", fontsize = 12];
    }


**Code of the new implementation**

::

    blockdiag sector_to_pages_mapping {

        node_width = 120; 
        node_height = 60;

        span_height = 60;
        span_width = 100;

        default_shape = roundedbox;

        default_group_color = none;
        default_fontsize = 14

        TCP_STACK [label = "TCP\n stack"];  
        EVNT_TASK [label = "event\n task"];  
        APPL_TASK [label = "application\n task", width=130];  
        WIFI_DRV  [label = "Wi-Fi\n Driver"];  
        SPACER [label = "", shape = none, width=1, height=1];

        TCP_STACK -> EVNT_TASK [label = "event", fontsize = 12];
        EVNT_TASK -> APPL_TASK [label = "callback\n or event", fontsize = 12];

        group {
           label = "default handler";
           fontsize = 12
           orientation = portrait;
           EVNT_TASK <- WIFI_DRV [label = "event", fontsize = 12];
        }

        group {
            label = "user handler";
            fontsize = 12
            orientation = portrait;
            APPL_TASK -- SPACER;
        }
        WIFI_DRV <- SPACER [label = "API\n call", fontsize = 12];
    }

blockdiag - example 3
"""""""""""""""""""""

**Current implementation with ASCII art**

::

     -------------              -------------              -------------
    | Application |            |    LwIP     |            |    Wi-Fi    |
    |    task     | ---------> |    task     | ---------> |    task     |
     -------------              -------------              -------------
      1> User data               2> Pbuf                    3> Dynamic (Static) TX Buffer

**New implementation**

.. blockdiag::

    blockdiag buffer_allocation_tx {

        node_width = 160; 
        node_height = 80;
        span_height = 10;
        span_width = 100;
        default_shape = roundedbox;
        default_fontsize = 16

        APPL_TASK [label = "Application\n task"];  
        LwIP_TASK [label = "LwIP\n task"];  
        WiFi_TASK [label = "Wi-Fi\n task"];

        APPL_DESC [label = "1> User data", fontsize=14, height=30, shape=note, color=yellow];  
        LwIP_DESC [label = "2> Pbuf", fontsize=14, height=30, shape=note, color=yellow];  
        WiFi_DESC [label = "3> Dynamic (Static) TX Buffer", fontsize=14, width=260, height=30, shape=note, color=yellow];

        APPL_TASK -> LwIP_TASK -> WiFi_TASK
        APPL_DESC -> LwIP_DESC -> WiFi_DESC [style=none]
    }


**Code of the new implementation**

::

    blockdiag buffer_allocation_tx {

        node_width = 160; 
        node_height = 80;
        span_height = 10;
        span_width = 100;
        default_shape = roundedbox;
        default_fontsize = 16

        APPL_TASK [label = "Application\n task"];  
        LwIP_TASK [label = "LwIP\n task"];  
        WiFi_TASK [label = "Wi-Fi\n task"];

        APPL_DESC [label = "1> User data", fontsize=14, height=30, shape=note, color=yellow];  
        LwIP_DESC [label = "2> Pbuf", fontsize=14, height=30, shape=note, color=yellow];  
        WiFi_DESC [label = "3> Dynamic (Static) TX Buffer", fontsize=14, width=260, height=30, shape=note, color=yellow];

        APPL_TASK -> LwIP_TASK -> WiFi_TASK
        APPL_DESC -> LwIP_DESC -> WiFi_DESC [style=none]
    }


packetdiag example
^^^^^^^^^^^^^^^^^^

http://blockdiag.com/en/nwdiag/packetdiag-examples.html

**Current implementation with ASCII art**

::

    +-----------+--------------+-------------+-----------+
    | State (4) | Seq. no. (4) | Unused (20) | CRC32 (4) | Header (32)
    +-----------+--------------+-------------+-----------+
    |                Entry state bitmap (32)             |
    +----------------------------------------------------+
    |                       Entry 0 (32)                 |
    +----------------------------------------------------+
    |                       Entry 1 (32)                 |
    +----------------------------------------------------+
    /                                                    /
    /                                                    /
    +----------------------------------------------------+
    |                       Entry 125 (32)               |
    +----------------------------------------------------+

**New implementation**

.. packetdiag::

    packetdiag {
        colwidth = 32  
        node_width = 15
        node_height = 32
        default_fontsize = 12

        0-3: State\n(4)
        4-7: Seq. no.\n(4)
        8-27: Unused (20)
        28-31: CRC32\n(4)
        32-63: Entry state bitmap (32)  
        64-95: Entry 0 (32)
        96-127: Entry 1 (32)
        128-191: --- [colheight = 2]
        192-223: Entry 125 (32)
    }


**Code of the new implementation**

::

    packetdiag {
        colwidth = 32  
        node_width = 15
        node_height = 32
        default_fontsize = 12

        0-3: State\n(4)
        4-7: Seq. no.\n(4)
        8-27: Unused (20)
        28-31: CRC32\n(4)
        32-63: Entry state bitmap (32)  
        64-95: Entry 0 (32)
        96-127: Entry 1 (32)
        128-191: --- [colheight = 2]
        192-223: Entry 125 (32)
    }


seqdiag example
^^^^^^^^^^^^^^^

http://blockdiag.com/en/seqdiag/index.html

**Current implementation with ASCII art**

::


    ---------           ---------           --------- 
   |  app    |         |  event  |         |   Wi-Fi |
   |  task   |         |   task  |         |   task  |
    ---------           ---------           --------- 
        |                   |                   |
        |                   |                   |
        |      1.1> Configure country code      |
        |-------------------------------------->|
        |      1.2> Scan configuration          |
        |-------------------------------------->|
        |                   |                   |
        |                   |                   |
        |                   |                   |----
        |                   |                   |    | 2.1> Scan channel 1
        |                   |                   |<---
        |                   |                   |----
        |                   |                   |    | 2.2> Scan channel 2
        |                   |                   |<---
        |                   |                   |
        |                   |                   |      ....  ...
        |                   |                   |
        |                   |                   |----
        |                   |                   |    | 2.x> Scan channel N
        |                   |                   |<---
        |                   |                   |
        |           3.1 SYSTEM_EVENT_SCAN_DONE  |
        |                   |<------------------|
        |  3.2 SYSTEM_EVENT_SCAN_DONE           |
        |<------------------|                   |
        |                   |                   |


**New implementation**

.. seqdiag::

    seqdiag {
        activation = none;
        edge_length = 160;
        span_height = 15;
        default_shape = roundedbox;
        default_fontsize = 12; 

        app_task; event_task; Wi-Fi_task; 

        app_task   -> Wi-Fi_task [label = "1.1 > Configure country code"];
        app_task   -> Wi-Fi_task [label = "1.2 > Scan configuration"];
        Wi-Fi_task -> Wi-Fi_task [label = "2.1 > Scan channel 1"];
        Wi-Fi_task -> Wi-Fi_task [label = "2.2 > Scan channel 2"];
        Wi-Fi_task -> Wi-Fi_task [label = "..."];
        Wi-Fi_task -> Wi-Fi_task [label = "2.N > Scan channel N"];
        event_task <- Wi-Fi_task [label = "3.1 > SYSTEM_EVENT_SCAN_DONE"];
        app_task <- event_task [label = "3.2 > SYSTEM_EVENT_SCAN_DONE"];
    }


**Code of the new implementation**

::

    seqdiag {
        activation = none;
        edge_length = 160;
        span_height = 15;
        default_shape = roundedbox;
        default_fontsize = 12; 

        app_task; event_task; Wi-Fi_task; 

        app_task   -> Wi-Fi_task [label = "1.1 > Configure country code"];
        app_task   -> Wi-Fi_task [label = "1.2 > Scan configuration"];
        Wi-Fi_task -> Wi-Fi_task [label = "2.1 > Scan channel 1"];
        Wi-Fi_task -> Wi-Fi_task [label = "2.2 > Scan channel 2"];
        Wi-Fi_task -> Wi-Fi_task [label = "..."];
        Wi-Fi_task -> Wi-Fi_task [label = "2.N > Scan channel N"];
        event_task <- Wi-Fi_task [label = "3.1 > SYSTEM_EVENT_SCAN_DONE"];
        app_task <- event_task [label = "3.2 > SYSTEM_EVENT_SCAN_DONE"];
    }
