/*=========================================================================

  Program:   ParaView
  Module:    vtkPVEnSightMasterServerTranslator.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPVEnSightMasterServerTranslator - 
// .SECTION Description

#ifndef vtkPVEnSightMasterServerTranslator_h
#define vtkPVEnSightMasterServerTranslator_h

#include "vtkExtentTranslator.h"
#include "vtkPVVTKExtensionsDefaultModule.h" //needed for exports

class VTKPVVTKEXTENSIONSDEFAULT_EXPORT vtkPVEnSightMasterServerTranslator : public vtkExtentTranslator
{
public:
  static vtkPVEnSightMasterServerTranslator* New();
  vtkTypeMacro(vtkPVEnSightMasterServerTranslator, vtkExtentTranslator);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  // Description:
  // Get/Set the piece that should provide the data.  All other pieces
  // should provide empty data.
  vtkGetMacro(ProcessId, int);
  vtkSetMacro(ProcessId, int);
  
  // Description:
  // Translates the piece matching ProcessId to the whole extent, and
  // all other pieces to empty.
  int PieceToExtentThreadSafe(int piece, int numPieces, int ghostLevel, 
                              int *wholeExtent, int *resultExtent, 
                              int splitMode, int byPoints);
protected:
  vtkPVEnSightMasterServerTranslator();
  ~vtkPVEnSightMasterServerTranslator();
  
  // The process id on which this translator is running.
  int ProcessId;
  
private:
  vtkPVEnSightMasterServerTranslator(const vtkPVEnSightMasterServerTranslator&) VTK_DELETE_FUNCTION;
  void operator=(const vtkPVEnSightMasterServerTranslator&) VTK_DELETE_FUNCTION;
};

#endif
