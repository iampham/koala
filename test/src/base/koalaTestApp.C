//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "koalaTestApp.h"
#include "koalaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
koalaTestApp::validParams()
{
  InputParameters params = koalaApp::validParams();
  return params;
}

koalaTestApp::koalaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  koalaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

koalaTestApp::~koalaTestApp() {}

void
koalaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  koalaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"koalaTestApp"});
    Registry::registerActionsTo(af, {"koalaTestApp"});
  }
}

void
koalaTestApp::registerApps()
{
  registerApp(koalaApp);
  registerApp(koalaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
koalaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  koalaTestApp::registerAll(f, af, s);
}
extern "C" void
koalaTestApp__registerApps()
{
  koalaTestApp::registerApps();
}
