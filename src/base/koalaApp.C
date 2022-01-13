#include "koalaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
koalaApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

koalaApp::koalaApp(InputParameters parameters) : MooseApp(parameters)
{
  koalaApp::registerAll(_factory, _action_factory, _syntax);
}

koalaApp::~koalaApp() {}

void
koalaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"koalaApp"});
  Registry::registerActionsTo(af, {"koalaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
koalaApp::registerApps()
{
  registerApp(koalaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
koalaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  koalaApp::registerAll(f, af, s);
}
extern "C" void
koalaApp__registerApps()
{
  koalaApp::registerApps();
}
