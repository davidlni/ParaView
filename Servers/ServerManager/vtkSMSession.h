/*=========================================================================

  Program:   ParaView
  Module:    $RCSfile$

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMSession
// .SECTION Description
// vtkSMSession is the default ParaView session. This class can be used as the
// session for non-client-server configurations eg. builtin mode or batch.
#ifndef __vtkSMSession_h
#define __vtkSMSession_h

#include "vtkSession.h"
#include "vtkSMMessage.h"

class vtkSMProxyManager;
class vtkSMSessionCore;

class VTK_EXPORT vtkSMSession : public vtkSession
{
public:
  static vtkSMSession* New();
  vtkTypeMacro(vtkSMSession, vtkSession);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  virtual bool GetIsAlive() { return true; }

//BTX
  // Description:
  // Push the state message.
  virtual void PushState(vtkSMMessage* msg);

  // Description:
  // Pull the state message.
  virtual void PullState(vtkSMMessage* msg);

  // Description:
  // Invoke a method remotely
  virtual void Invoke(vtkSMMessage* msg);

  // Description:
  // Delete server side object. (PMObject)
  virtual void DeletePMObject(vtkSMMessage* msg);
//ETX

  // Description:
  // Provides access to the session core.
  vtkGetObjectMacro(Core, vtkSMSessionCore);

  // Description:
  // Provides a unique identifier across processes of that session
  virtual vtkTypeUInt32 GetNextGlobalUniqueIdentifier()
    {
    this->LastGUID++;
    return this->LastGUID;
    }

  // Description:
  // Returns the vtkSMProxyManager attached to that session. Note that the
  // ProxyManager may not be active on every process e.g. in client-server
  // configurations, the proxy manager is active only on the client. Using the
  // proxy-manager on the server in such a session can have unexpected results.
  virtual vtkSMProxyManager* GetProxyManager();

//BTX
protected:
  vtkSMSession();
  ~vtkSMSession();

  vtkSMSessionCore* Core;
  vtkSMProxyManager* ProxyManager;

  // FIXME should be managed smartly between client and server.
  vtkTypeUInt32 LastGUID;

private:
  vtkSMSession(const vtkSMSession&); // Not implemented
  void operator=(const vtkSMSession&); // Not implemented
//ETX
};

#endif