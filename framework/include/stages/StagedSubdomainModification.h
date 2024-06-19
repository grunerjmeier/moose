//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

// Moose Includes
#include "StagedBase.h"

/**
 * Base class for deriving Stages
 */
class StagedSubdomainModification : public StagedBase
{
public:
  static InputParameters validParams();

  StagedSubdomainModification(const InputParameters & parameters);
  
  SubdomainName getSubdomainFrom();
  SubdomainName getSubdomainTo();

private:
  const SubdomainName _subdomain_from;
  const SubdomainName _subdomain_to;

};