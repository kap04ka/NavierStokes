#pragma once
#include "BasicSolver.hpp"
#include "VorticityStreamFunctionSolver.hpp"
#include "VelocityPressureSolver.hpp"
#include <memory>
#include <string>

class SolverFactory {
public:
    static std::unique_ptr<BasicSolver> createSolver(const std::string& method, std::shared_ptr<ILogger> logger);
};