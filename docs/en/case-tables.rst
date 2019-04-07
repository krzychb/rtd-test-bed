Test Case - Rendering of Tables
===============================

+-----------------------+------------------------------------------------------------------------------------------+
| Function              | Description                                                                              |
+=======================+==========================================================================================+
|Self-healing           |Self-healing allows such routing-based network to operate when a node breaks down or when |
|                       |a connection becomes unreliable.                                                          |
|                       |                                                                                          |
|                       |If a root node breaks down, the nodes directly connected with it on the second layer will |
|                       |detect the root-node failure quickly and initialize a new round of root node election. If |
|                       |the root node and all the nodes on the second layer break down, the nodes on the third    |
|                       |layer will initialize root node election and a new root node will be elected eventually.  |
|                       |                                                                                          |
|                       |In the event of a failure of the intermediate nodes and the leaf nodes, failed nodes will |
|                       |reconnect their parent nodes respectively for a predefined number of times and will, then,|
|                       |reselect a new parent node to join the mesh network.                                      |
+-----------------------+------------------------------------------------------------------------------------------+
|Root node switch       |Users can call :cpp:func:`esp_mesh_waive_root` to switch root nodes in the network.       |
|                       |The new root node can be specified by the users or be automatically elected by the        |
|                       |network.                                                                                  |
+-----------------------+------------------------------------------------------------------------------------------+
|Root conflicts handling|Only the conflicts of root nodes connecting to the same router are handled. Conflicts of  |
|                       |root nodes having the same router SSID, but different router BSSID, are not handled.      |
+-----------------------+------------------------------------------------------------------------------------------+
|Parent node switch     |Changing the physical position of a node in the mesh network will lead to declined signal |
|                       |strength of the parent node and problematic communication. Upon detecting such a problem, |
|                       |this function will automatically choose a better parent node for this node.               |
|                       |                                                                                          |
|                       |When the position of a mobile node changes constantly, communication with the parent node |
|                       |deteriorates or even drops. After such a situation is detected, the parent of the mobile  |
|                       |node is automatically reselected, so that communication with the network is maintained.   |
+-----------------------+------------------------------------------------------------------------------------------+
|Loopback avoidance,    |During the parent selection, the nodes covered in its own routing table are excluded,     |
|detection and handling |so that the occurrence of a loopback is avoided.                                          |
|                       |                                                                                          |
|                       |The path verification mechanism and the energy transfer mechanism are used for detecting  |
|                       |the loopback.                                                                             |
|                       |                                                                                          |
|                       |When a loopback is detected, the parent node will disconnect with the child node and      |
|                       |inform it about the occurrence of the loop with a predefined reason code.                 |
+-----------------------+------------------------------------------------------------------------------------------+
