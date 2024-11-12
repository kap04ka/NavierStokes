#pragma once
#include "BasicSolver.hpp"
#include "VelocityPressureSolver.hpp"
#include "VelocityPressureSolverOMP.hpp"
#include "VorticityStreamFunctionSolver.hpp"
#include "VorticityStreamFunctionSolverOMP.hpp"
#include <memory>
#include <string>

class SolverFactory {
public:
    static std::unique_ptr<BasicSolver> createSolver(const std::string& method, std::shared_ptr<ILogger> logger);
};