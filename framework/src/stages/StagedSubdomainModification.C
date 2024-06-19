//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "StagedSubdomainModification.h"

registerMooseObject("moose_bare_tmechApp", StagedSubdomainModification);

InputParameters
StagedSubdomainModification::validParams()
{
  InputParameters params = StagedBase::validParams();
  // params.declareControllable("enable"); // allows Control to enable/disable this type of object
  // params.registerBase("StagedSubdomainModification");
  params.addParam<SubdomainName>("from",
                                 "Subdomain to move all elements from.");
  params.addParam<SubdomainName>("to",
                                 "Subdomain to move all elements to.");
  params.addClassDescription("User object that bla bla bla.");
  return params;
}

StagedSubdomainModification::StagedSubdomainModification(const InputParameters & parameters)
  : StagedBase(parameters),
    _subdomain_from(getParam<SubdomainName>("from")),
    _subdomain_to(getParam<SubdomainName>("to"))
{
  std::cout << "StagedSubdomainModification::StagedSubdomainModification" << "\n";
}

// void 
// StagedSubdomainModification::setup(std::shared_ptr<FEProblemBase> p)
// {
//   // ToDo: make sure there is one user object of type TimedSubdomainModifier with from_stages=true
//   // p->hasOserObject(...)
// }

SubdomainName
StagedSubdomainModification::getSubdomainFrom()
{
  return _subdomain_from;
}

SubdomainName
StagedSubdomainModification::getSubdomainTo()
{
  return _subdomain_to;
}