/*=========================================================================

  Program:   ParaView
  Module:    vtkPVDataSizeInformation.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPVDataSizeInformation - PV information object for getting
// information about data size.
// .SECTION Description
// vtkPVDataSizeInformation is an information object for getting information
// about data size. This is a light weight sibling of vtkPVDataInformation which
// only returns the data size and nothing more. The data size can also be
// obtained from vtkPVDataInformation.

#ifndef vtkPVDataSizeInformation_h
#define vtkPVDataSizeInformation_h

#include "vtkPVClientServerCoreCoreModule.h" //needed for exports
#include "vtkPVInformation.h"

class VTKPVCLIENTSERVERCORECORE_EXPORT vtkPVDataSizeInformation : public vtkPVInformation
{
public:
  static vtkPVDataSizeInformation* New();
  vtkTypeMacro(vtkPVDataSizeInformation, vtkPVInformation);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Transfer information about a single object into this object.
  virtual void CopyFromObject(vtkObject*);

  // Description:
  // Merge another information object. Calls AddInformation(info, 0).
  virtual void AddInformation(vtkPVInformation* info);

  // Description:
  // Manage a serialized version of the information.
  virtual void CopyToStream(vtkClientServerStream*);
  virtual void CopyFromStream(const vtkClientServerStream*);

  // Description:
  // Remove all information.  The next add will be like a copy.
  void Initialize();

  // Description:
  // Access to memory size information.
  vtkGetMacro(MemorySize, int);

protected:
  vtkPVDataSizeInformation();
  ~vtkPVDataSizeInformation();

  int MemorySize;
private:
  vtkPVDataSizeInformation(const vtkPVDataSizeInformation&) VTK_DELETE_FUNCTION;
  void operator=(const vtkPVDataSizeInformation&) VTK_DELETE_FUNCTION;

};

#endif

