//
//  Header.h
//  minix_system_call
//
//  Created by Florentin Rochet on 4/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef minix_system_call_Header_h
#define minix_system_call_Header_h

_PROTOTYPE(int getrlimit, (int resource, struct rlimit *rlim));

_PROTOTYPE(int setrlimit, (int resource,struct rlimit *rlim));
#endif
