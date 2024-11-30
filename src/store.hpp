#ifndef STORE_HPP
#define STORE_HPP

#include <U8g2lib.h>
#include <state_machine.hpp>

namespace RumeLab::Detail
{

    template <typename = void>
    class Store
    {
    public:
        using StateType = State<Store>;

    private:
    public:
        StateType *main_state;
        StateType *red_pill_state;
        StateType *blue_pill_state;

        Store(
            StateType *p_main_state,
            StateType *p_red_pill_state,
            StateType *p_blue_pill_state,
            const uint8_t *p_font = u8g2_font_5x7_tf) : main_state(p_main_state),
                                                        red_pill_state(p_red_pill_state),
                                                        blue_pill_state(p_blue_pill_state) {}
    };

} // namespace RumeLab::Detail

using Store = RumeLab::Detail::Store<>;

#endif // STORE_HPP