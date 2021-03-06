/*=========================================================================

  Program:   ParaView
  Module:    vtkPartitionOrderingInterface.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPartitionOrderingInterface - Interface for ordering compositing.
//
// .SECTION Description
//      An interface class to get the order of process for parallel
//      compositing.
//
// .SECTION See Also
//      vtkPKdTree,vtkPartitionOrdering

#ifndef vtkPartitionOrderingInterface_h
#define vtkPartitionOrderingInterface_h

#include "vtkPVVTKExtensionsRenderingModule.h" // needed for export macro
#include "vtkObject.h"
#include "vtkSmartPointer.h" // For automatic reference counting

class vtkDataSet;
class vtkIntArray;
class vtkMultiProcessController;

class VTKPVVTKEXTENSIONSRENDERING_EXPORT vtkPartitionOrderingInterface : public vtkObject
{
public:
  vtkTypeMacro(vtkPartitionOrderingInterface, vtkObject);

  void PrintSelf(ostream& os, vtkIndent indent);
  static vtkPartitionOrderingInterface *New();

  // the number of processes
  int GetNumberOfRegions();

  // Description:
  // Return a list of all processes in order from front to back given a
  // vector direction of projection.  Use this to do visibility sorts
  // in parallel projection mode. `orderedList' will be resized to the number
  // of processes. The return value is the number of processes.
  // \pre orderedList_exists: orderedList!=0
  int ViewOrderAllProcessesInDirection(const double directionOfProjection[3],
                                       vtkIntArray *orderedList);

  // Description:
  // Return a list of all processes in order from front to back given a
  // camera position.  Use this to do visibility sorts in perspective
  // projection mode. `orderedList' will be resized to the number
  // of processes. The return value is the number of processes.
  // \pre orderedList_exists: orderedList!=0
  int ViewOrderAllProcessesFromPosition(const double cameraPosition[3],
                                        vtkIntArray *orderedList);

  // Description:
  // Set the implementation to use for the view order methods. Current options
  // are vtkPKdTree and vtkPartitionOrdering.
  void SetImplementation(vtkObject* implementation);
  vtkObject* GetImplementation()
  {
    return this->Implementation;
  }

  virtual vtkMTimeType GetMTime();

protected:
  vtkPartitionOrderingInterface();
  ~vtkPartitionOrderingInterface();

private:
  // Implementation must be either a vtkPKdTree object or a vtkPartitionOrdering object.
  vtkSmartPointer<vtkObject> Implementation;

  vtkPartitionOrderingInterface(const vtkPartitionOrderingInterface&) VTK_DELETE_FUNCTION;
  void operator=(const vtkPartitionOrderingInterface&) VTK_DELETE_FUNCTION;
};

#endif
