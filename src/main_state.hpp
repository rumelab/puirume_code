#ifndef MAIN_STATE_HPP
#define MAIN_STATE_HPP

#include "store.hpp"
#include "items.hpp"

namespace RumeLab::Detail
{

    template <typename = void>
    class MainState : public ::State<::Store>
    {
    public:
    private:
        inline auto is_selecting_blue_pill() -> bool
        {
            return (input_device.get_rotation() % 2) == 0;
        }

        auto draw() -> void
        {
            output_device.firstPage();
            do
            {
                output_device.drawStr(0, 10, "Blue pill red pill?");
                output_device.drawHLine(0, is_selecting_blue_pill() ? 45 : 55, 60);
                output_device.drawStr(0, 45, "Blue Pill.");
                output_device.drawStr(0, 55, "Red Pill.");
            } while (output_device.nextPage());
        }

    public:
        auto enter(StateMachineType &p_state_machine) -> void override
        {
            input_device.reset_rotation();
            draw();
        }

        auto process(StateMachineType &p_state_machine, uint32_t p_delta) -> void override
        {
            if (input_device.get_last_step() != 0)
                draw();

            if (input_device.is_just_released())
                p_state_machine.to(is_selecting_blue_pill() ? p_state_machine.store.blue_pill_state : p_state_machine.store.red_pill_state);
        }
    };

} // namespace RumeLab::Detail

using MainState = RumeLab::Detail::MainState<>;

#endif // MAIN_STATE_HPP