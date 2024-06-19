//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "AddStagesAction.h"
#include "FEProblem.h"

registerMooseAction("moose_bare_tmechApp", AddStagesAction, "add_stages");

InputParameters
AddStagesAction::validParams()
{
  InputParameters params = MooseObjectAction::validParams();
  params.addClassDescription("Add a Stages object to the simulation.");
  return params;
}

AddStagesAction::AddStagesAction(const InputParameters & params) : MooseObjectAction(params)
{
}

void
AddStagesAction::act()
{
  std::cout << "AddStagesAction.act: _type = " << _type << "; " << "_name = " << _name << "\n";

  // only add ONE stages user object
  if (_problem->hasUserObject("Stages") == false)
    _problem->addUserObject(/*type=*/"Stages", /*name=*/"Stages", _moose_object_pars);
    
}