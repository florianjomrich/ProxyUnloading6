//
// Copyright (C) 2000 Institut fuer Nachrichtentechnik, Universitaet Karlsruhe
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//




network UDPSockets
{
    submodules:
        // server
        server1: UDPSocketHost {
            parameters:
                client_name = "UDPSocketTestServer";
                routingFile = "server1.irt";
                @display("p=40,83");
            gates:
                in[1];
                out[1];
        };
        // clients
        client2: UDPSocketHost {
            parameters:
                client_name = "UDPSocketTestClient";
                routingFile = "client2.irt";
                @display("p=200,83");
            gates:
                in[1];
                out[1];
        };
    connections:
        server1.out[0] --> {  datarate = 1000000; } --> client2.in[0];
        client2.out[0] --> {  datarate = 1000000; } --> server1.in[0];
}

