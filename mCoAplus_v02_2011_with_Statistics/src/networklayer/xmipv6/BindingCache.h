/**
 * Copyright (C) 2007
 * Faqir Zarrar Yousaf
 * Communication Networks Institute, University of Dortmund, Germany.
 * Christian Bauer
 * Institute of Communications and Navigation, German Aerospace Center (DLR)

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef __BINDINGCACHE_H__
#define __BINDINGCACHE_H__

#include <vector>
#include <omnetpp.h>
#include "INETDefs.h"
#include "IPv6Address.h"
#include "InterfaceTable.h"
//added by zarrar on 12.06.07
#include "MobilityHeader_m.h"

// added by Bruno Sousa 2010/5/4 [MCOA]
#include "KeyMCoABind.h"


// these token must be equal to those in the BindingUpdateList file!
#define HO_TOKEN	1101
#define CO_TOKEN	2101

class INET_API BindingCache : public cSimpleModule
{
	private:
	  //###########################Declaration of BUL and BC added by Zarrar Yousaf @ CNI Uni Dortmund on 04.06.07######
	  /* Section 9.1
	     Each Binding Cache entry conceptually contains the following fields: */
	  struct BindingCacheEntry
	  {

		  /*o  The home address of the mobile node for which this is the Binding
			  Cache entry.  This field is used as the key for searching the
      		  Binding Cache for the destination address of a packet being sent.*/
		  // this is stored as the key to the entry
		  /*o  The care-of address for the mobile node indicated by the home
      		   address field in this Binding Cache entry.*/
		  IPv6Address careOfAddress;
		  /*o  A lifetime value, indicating the remaining lifetime for this
      		   Binding Cache entry.  The lifetime value is initialized from the
      		   Lifetime field in the Binding Update that created or last modified
      		   this Binding Cache entry.*/
   		  uint bindingLifetime;
		  /*o  A flag indicating whether or not this Binding Cache entry is a
      		   home registration entry (applicable only on nodes which support
      		   home agent functionality).*/
   		  bool isHomeRegisteration; 	//if FALSE, it is Correspondent Registeration
   		  /*o  The maximum value of the Sequence Number field received in
			   previous Binding Updates for this home address.  The Sequence
			   Number field is 16 bits long.  Sequence Number values MUST be
			   compared modulo 2**16 as explained in Section 9.5.1.*/
   		  uint sequenceNumber; 	//Sequence number of BU message sent
   		  /*o  Usage information for this Binding Cache entry.  This is needed to
      		   implement the cache replacement policy in use in the Binding
      		   Cache.  Recent use of a cache entry also serves as an indication
      		   that a Binding Refresh Request should be sent when the lifetime of
      		   this entry nears expiration.*/
   		  // omitted
	  };
	  /* As before MCoA implementation // Modified by Bruno Sousa
	  typedef std::map<IPv6Address,BindingCacheEntry> BindingCache6; //The IPv6 Address KEY of this map is the HomeAddress of the MN
	  BindingCache6 bindingCache;
		*/
	  typedef std::map<KeyMCoABind,BindingCacheEntry> BindingCache6; //The IPv6 Address+BID KEY of this map is the HomeAddress of the MN
	  BindingCache6 bindingCache;

	  friend std::ostream& operator<<(std::ostream& os, const BindingCacheEntry& bce);

  public:
	  BindingCache();
	  virtual ~BindingCache();

  protected:
	  int numInitStages() const  {return 2;}
	  virtual void initialize(int stage);

	  /**
	   * Raises an error.
	   */
	  virtual void handleMessage(cMessage *);

  public:
	  /**
	   * Sets Binding Cache Entry (BCE) with provided values. If BCE does not yet exist, a new one will be created.
	   */
	  void addOrUpdateBC(const KeyMCoABind& hoa, const IPv6Address& coa, const uint lifetime, const uint seq, bool homeReg);

	  /**
	   * Returns sequence number of BCE for provided HoA.
	   */
	  uint readBCSequenceNumber(const KeyMCoABind& HoA); // update 10.9.07 - CB

	  uint readBCSequenceNumberOnlyAddr(const IPv6Address& HoA, uint seqNumber); // Bruno Sousa 2010/5/13

	  /**
	   * Added by CB, 29.08.07
	   * Checks whether there is an entry in the BC for the given HoA and CoA
	   */
	  bool isInBindingCache(const KeyMCoABind& HoA, IPv6Address& CoA);

	  /**
	   * Added by CB, 4.9.07
	   * Checks whether there is an entry in the BC for the given HoA
	   */
	  bool isInBindingCache(const KeyMCoABind& HoA);


	  /**
	 	* Added by Bruno Sousa, 2010/5/4
	 	* Checks whether there is an entry in the BC only by the BID part
	 	*/
	 bool isInBindingCacheOnlyBID(const uint iBID);


	  /**
	   * Added by CB, 4.9.07
	   * Delete the entry from the cache with the provided HoA.
	   *
	   * Modified by Bruno Sousa to include return of operation
	   */
	  bool deleteEntry(KeyMCoABind& HoA);

	  /**
	   * Delete all entries
	   *
	   */
	  bool deleteALLEntries();

	  /**
	   * Returns the value of the homeRegistration flag for the given HoA.
	   */
	  bool getHomeRegistration(const KeyMCoABind& HoA); // 10.9.07 - CB

	  bool getHomeRegistrationOnlyAddr(const IPv6Address& HoA, uint seqNumber);

	  /**
	   * Returns the lifetime of the binding for the given HoA.
	   */
	  uint getLifetime(const KeyMCoABind& HoA); // 10.9.07 - CB


	/**
	 * Generates a home token from the provided parameters.
	 * Returns a static value for now.
	 */
	virtual int generateHomeToken(const IPv6Address& HoA, int nonce);

	/**
	 * Generates a care-of token from the provided paramters.
	 * Returns a static value for now.
	 */
	virtual int generateCareOfToken(const IPv6Address& CoA, int nonce);


	/**
	 * Generates the key Kbm from home and care-of keygen token.
	 * For now, this return the sum of both tokens.
	 */
	virtual int generateKey(int homeToken, int careOfToken, const IPv6Address& CoA);


	/*Bruno Sousa 2010/5/5 */
	void prtBindings(void);

	int getBCSize(void);
};

#endif
