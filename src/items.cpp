#include "items.hpp"

#include "main_state.hpp"
#include "red_pill_state.hpp"
#include "blue_pill_state.hpp"

OutputDeviceType output_device(U8G2_R0);
InputDeviceType input_device;

static MainState main_state;
static RedPillState red_pill_state;
static BluePillState blue_pill_state;

StateMachine<Store> state_machine(
    Store(
        &main_state,
        &red_pill_state,
        &blue_pill_state));