#include "SolverFactory.hpp"
#include <stdexcept>

std::unique_ptr<BasicSolver> SolverFactory::createSolver(const std::string& method, std::shared_ptr<ILogger> logger) {
    if (method == "vorticity-stream") {
        return std::make_unique<VorticityStreamFunctionSolver>(logger);
    } else if (method == "velocity-pressure") {
        return std::make_unique<VelocityPressureSolver>(logger); 
    } else if (method == "q" || method == "quit") {
        return nullptr;
    } else {
        throw std::invalid_argument("Invalid method.");
    }
}