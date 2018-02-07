# FrontPanelBroker
###### **A simple I/O arbiter and baord manager for the OpalKelly FrontPanel ® FPGA - USB/PCI communication driver written in C++.**

**NOTE 1:** [*FrontPanel*](https://www.opalkelly.com/products/frontpanel/) is a registered tradmark of [*OpalKelly*](https://www.opalkelly.com/) which also owns all the code and binaries with the included FrontPanel SDK and APIs. The latest versions can be obtained [here](https://pins.opalkelly.com/downloads).

**NOTE 2:** *FrontPanelBroker* is distributed under the [MIT license](https://choosealicense.com/licenses/mit/).
### Features
1. Handles multiple OpalKelly FPGA boards using a simple syntax.
2. Automatically selects the appropriate FrontPanel APIs based on the bus type (USB 2.0/USB 3.0/PCI).
3. Burn a bitfile to the FPGA as soon as we open a connection to it.
4. Sensible error messages. **:-)**
5. Semi-automatic PLL handling for quick and easy deployment.

### Usage
* This library easy to use so long as FrontPanel is already installed on your system! Simply include the include the source code (.h, .cpp files) and use it in your code.
* Linux users may also consider using the compiled shared (.so) libraries along with the header file. **(Coming soon!)**
* Windows users may, alternatively use the compiled dynamic link library (DLL) along with the header file. **(Coming soon!)**

### OpalKelly FrontPanel Installation
Instructions to install FrontPanel on your computer are available along with the SDK in the *README.txt* file. 
