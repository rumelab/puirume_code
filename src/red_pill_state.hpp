#ifndef RED_PILL_STATE_HPP
#define RED_PILL_STATE_HPP

#include "store.hpp"

namespace RumeLab::Detail
{

    template <typename = void>
    class RedPillState : public ::State<::Store>
    {
    public:
    private:
        auto draw() -> void
        {
            output_device.firstPage();
            do
            {
                output_device.drawStr(0, 10, "Fast food is bad.");

                output_device.drawHLine(0, 45, 60);
                output_device.drawStr(0, 45, "Return.");
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
            if (input_device.is_just_released())
                p_state_machine.to(p_state_machine.store.main_state);
        }
    };

} // namespace RumeLab::Detail

using RedPillState = RumeLab::Detail::RedPillState<>;

#endif // RED_PILL_STATE_HPP