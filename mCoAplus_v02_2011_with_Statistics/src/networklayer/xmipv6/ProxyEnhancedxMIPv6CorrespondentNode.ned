//
// Copyright (C) 2007 
// Faqir Zarrar Yousaf
// Communication Networks Institute, Dortmund University of Technology (TU Dortmund), Germany.
// Christian Bauer
// Institute of Communications and Navigation, German Aerospace Center (DLR)
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

package inet.networklayer.xmipv6;

//
// Implements xMIPv6 (where x = F, H, F-H).
//
simple ProxyEnhancedxMIPv6ForCorrespondentNode
{
	parameters:
		//string homePrefix;
		//string CNAddress;
		//string CNAddress1;
		bool isHomeAgent;
		bool isMobileNode;
	gates:
		input fromIPv6;
		output toIPv6;
		
	
		//PROXY EXTENSION FJ
		inout xMIP_proxy_Enhanced_Control_Channel_CN[];
		
        inout XMIP_LAYER_CN_TO_HA;
        inout XMIP_LAYER_CN_TO_MN;
}

