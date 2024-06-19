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
class StagedFunctionValueChange : public StagedBase
{
public:
  enum class StepFunctionType
  {
    LINEAR = 0,
    SMOOTH = 1,
    PERLIN = 2
  };

  static InputParameters validParams();

  StagedFunctionValueChange(const InputParameters & parameters);

  virtual void setup(std::shared_ptr<FEProblemBase> p) override;
  
  std::string getVariableName();
  StepFunctionType getStepFunctionType();
  double getNewValue();
  Real getStartTime();
  Real getEndTime();

  double getValue(const Real t, const double old_value);
  double getTimeDerivative(const Real t, const double old_value);

  std::vector<Real> getTimesForTimeStepper() override;

private:
  const std::string _function_name;
  const StepFunctionType _step_function_type;
  const double _new_value;
  const Real _start_time;
  const Real _end_time;

  Real parseTime(std::string s);

};