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

    blockdiag wifi_programming_model {

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
        KNOT [shape = none];

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
            APPL_TASK -- KNOT;
        }
        WIFI_DRV <- KNOT [label = "API\n call", fontsize = 12];
    }

**Code of the new implementation**

::

    blockdiag wifi_programming_model {

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
        KNOT [shape = none];

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
            APPL_TASK -- KNOT;
        }
        WIFI_DRV <- KNOT [label = "API\n call", fontsize = 12];
    }

Bring this code to the `interactive shell <http://interactive.blockdiag.com/?compression=deflate&src=eJyNUl1rwjAUffdXBJ9XUDf2Uh0UnSAOV2bRBychbWMbjElJo44N__uutemHVra89eTck3POrc9lsA0ZidCRbRhOlIwU2e2YiPBOhpSjn1YLwRHwgY8s1DEaoG6vY5doTFkUa4CfAc3gNCGiDhdoIdEx5JBuyJ5rnMYkoXCj5F6ENPTl1xUhgpsEB5JLBTQhBbVr9xspdMq-zxrdp8uoN3Tx3HOGU7TixIc0A9QG7FOgVJNg215fFF4XMw97zrxKowcqNBA1SQue47pv1zySJJwFRDMpDPsBZSkH3cdOPricjCd49LFAlcEls8YMRkaKHagyT0xn7x5amS7OIdf2dRbr5b5jeLzaQ-8mIQw3xQgI5z5UAoag3ntSmVa2B_gv0OUUEvkeUExEyCGRbRg1FQNKxeCNrDfAE6m0IkwXM6XhvlXW97-wp0afpdF9StWty2abf_mslGlZ2faMh9re-1a-2cKE406g63PtDSlOv52pCUo>`__ and try out some modifications. 


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

Bring this code to the `interactive shell <http://interactive.blockdiag.com/?compression=deflate&src=eJylUtFqgzAUffcrLj5tYEHbUQZFwa0rjPVBsKODrUg0sYZmiWjEurF_X6qz2uxlsLzdcw_3nntOjJiJ5IAp2kNcpSkpIsQUgiQVPJJH-DQMUI8LTKKaYpmBC87cXsAAZ4TuM6nwW3vRomWO-IA6Y_Q8wv5BMUlRxWRUZignqlGIimOCY3G87KeCy5J-kHZ9p8kPgnW08cMneGUoJky1TD_PGe3Uv3GQqDyYuwV0Ytf1Y6DzT9gv4pauqE7c0smKDsyRguVDeD8iOh48l6QAjCQyLeh1u86NBZ0n7sy2oL3X5UISCxLBROE2RBlfX6rVZk89CFRK_xnb3qaNnXmwbDh6pwlchVKZl1zD5gXu2v-gL2sTdKdz-4979awm3igIVZzN1hzteX0xEl7Khp2WcbIzvr4BdebU_g>`__ and try out some modifications. 


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

Bring this code to the `interactive shell <http://interactive.blockdiag.com/packetdiag/?compression=deflate&src=eJxFkEETwTAQhe9-xR7rsKbZtKVmnIw_wDhhTEhoBim6xmD8d2mK7vF7b9_b5Ky2B8Paqj28OuBnWx7vVnMBI5AEEJgrtVn_qEhbVhi7LzhYA9Rmp25HXu9Kx5V9mtpOnSDFKIcwY8Vm6aKkG1iCfc_MpefTei0eIHk-d7fKaIgobigNUIohjKdjSa1XEmY-eOL4-oCqjoeN5ZM6QySp-70_SzBPf6Y4KIHnGYq6qhFEKwhfJnLfhoiw8F_yfyitGkNOSPQvFpQ2y-8P4LpTng>`__ and try out some modifications. 


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

Bring this code to the `interactive shell <http://interactive.blockdiag.com/seqdiag/?compression=deflate&src=eJyVkU1PwzAMhu_7FdburWgQXAqT0Cg3yqETCCEUZYvbRlROadOJD_Hf8ZpNdONDNJdYr_0-dpwWn7VRBbxPgI9aObNWzliCcyBLGPcy6gJlhVS4kvXo9MjLba1IlmiK0m3kE69qzFVXOdmWqkbWG9uRRr20L_v53JJrzdumJBIxTPwAdS2dap9iwDWS28Z3Jrgy23i_jsNgNsjDQ6WWWDFzGoURzGBuKTdF1yCseA7XvPKtcfoY_x8jGJOtFLHTs_oF7RAD028I0U_iEaUiYjUaZReHdjHCHobhqGbpYbN0Z__6EjgLfrYf-6feZ4vkWia3SbqQ2fwilZc3afJt6QwZIIcQ8Sfk4xONUM9f>`__ and try out some modifications. 