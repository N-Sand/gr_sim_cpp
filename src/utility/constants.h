#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace constants {
    // Speed of light in vacuum (c) 
    constexpr double speed_of_light = 1.0; // c = 1

    // Gravitational constant (G) 
    constexpr double gravitational_constant = 1.0; // G = 1

    // Planck constant (h-bar) 
    constexpr double planck_constant = 1.0; // ħ = 1

    // Boltzmann constant (k_B) 
    constexpr double boltzmann_constant = 1.0; // k_B = 1

    // Astronomical unit (AU) 
    constexpr double astronomical_unit = 1.495978707e11; // AU in meters

    // Parsec (pc) in natural units
    constexpr double parsec = 3.085677581e16; // pc in meters

    // Light year (ly) in natural units
    constexpr double light_year = 9.4607304725808e15; // ly in meters

    // geometric energy to SI 
    constexpr double energy_to_si = 1.2102e44; // energy in Joules

    // geometric mass to SI
    constexpr double mass_to_si = 1.3466e27; // mass in kilograms

    // Solar mass (M_sun)
    constexpr double solar_mass = 1.989e30 / mass_to_si;

    // Geometric velocity to SI
    constexpr double velocity_to_si = 2.9979e8; // velocity in meters per second (this is c)
}

#endif // CONSTANTS_H_