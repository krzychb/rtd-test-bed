Test Case - Block Diagram
=========================

Evaluation of `blockdiag - simple diagram images generator <http://blockdiag.com/en/index.html>`

.. blockdiag::

    blockdiag sector_to_pages_mapping {

        default_group_color = lightgrey;
        span_width = 40;

        P1 [label = "Page 1\nFull\n#11", height=60, width=60];
        P2 [label = "Page 2\nFull\n#12", height=60, width=60];
        P3 [label = "Page 3\nActive\n#13", height=60, width=60];
        P4 [label = "Page 4\nEmpty\n#", height=60, width=60];
        PN [label = "<- page #\n<- states\n<- sequence #", height=80];


        S3 [label = "Sector 3", width=70];
        S0 [label = "Sector 0", width=70];
        S2 [label = "Sector 2", width=70];
        S1 [label = "Sector 1", width=70];
        SN [label = "<- physical sectors"];

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