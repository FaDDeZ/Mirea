#include <stdio.h>
#include <limits.h>
#include "automate.h"

#if defined(PNEUMO_SUMYLATE)
#define TIMEOUT_DELTA(timeout)  1
#define  DELAY_DELTA(delay)     1
#else
#define TIMEOUT_DELTA(timeout)  ((timeout) * 1000)
#define  DELAY_DELTA(delay)     ((delay) * 1000)
#endif

#if defined(PNEUMO_DEBUG)
static char *state_names[] = {
        "PneumoState_I", "PneumoState_1", "PneumoState_2", "PneumoState_3", "PneumoState_4",
        "PneumoState_5", "PneumoState_6", "PneumoState_7", "PneumoState_8", "PneumoState_9",
        "PneumoState_10", "PneumoState_11", "PneumoState_12", "PneumoState_13", "PneumoState_14",
        "PneumoState_15", "PneumoState_16", "PneumoState_17", "PneumoState_18", "PneumoState_E",
}
#endif

void pneumo_engine_init(struct PneumoEngine *engine) {
    if (0 != engine) {
        engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;

        engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;

        engine->state = PneumoState_Init;
        engine->delay = 0;
        engine->timeout = 0;
        engine->timeouts[PneumoState_Init] = INT_MAX;
        engine->delays[PneumoState_Init] = INT_MAX;
        engine->timeouts[PneumoState_0] = TIMEOUT_DELTA(30);
        engine->delays[PneumoState_0] = TIMEOUT_DELTA(45);
        engine->timeouts[PneumoState_1] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_1] = TIMEOUT_DELTA(45);
        engine->timeouts[PneumoState_2] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_2] = TIMEOUT_DELTA(60);
        engine->timeouts[PneumoState_3] = TIMEOUT_DELTA(60);
        engine->delays[PneumoState_3] = TIMEOUT_DELTA(70);
        engine->timeouts[PneumoState_4] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_4] = TIMEOUT_DELTA(33);
        engine->timeouts[PneumoState_5] = TIMEOUT_DELTA(30);
        engine->delays[PneumoState_5] = TIMEOUT_DELTA(70);
        engine->timeouts[PneumoState_6] = TIMEOUT_DELTA(45);
        engine->delays[PneumoState_6] = TIMEOUT_DELTA(33);
        engine->timeouts[PneumoState_7] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_7] = TIMEOUT_DELTA(60);
        engine->timeouts[PneumoState_8] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_8] = TIMEOUT_DELTA(78);
        engine->timeouts[PneumoState_9] = TIMEOUT_DELTA(60);
        engine->delays[PneumoState_9] = TIMEOUT_DELTA(45);
        engine->timeouts[PneumoState_10] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_10] = TIMEOUT_DELTA(70);
        engine->timeouts[PneumoState_11] = TIMEOUT_DELTA(60);
        engine->delays[PneumoState_11] = TIMEOUT_DELTA(33);
        engine->timeouts[PneumoState_12] = TIMEOUT_DELTA(30);
        engine->delays[PneumoState_12] = TIMEOUT_DELTA(60);
        engine->timeouts[PneumoState_13] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_13] = TIMEOUT_DELTA(78);
        engine->timeouts[PneumoState_14] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_14] = TIMEOUT_DELTA(70);
        engine->timeouts[PneumoState_15] = TIMEOUT_DELTA(56);
        engine->delays[PneumoState_15] = TIMEOUT_DELTA(60);
        engine->timeouts[PneumoState_16] = TIMEOUT_DELTA(30);
        engine->delays[PneumoState_16] = TIMEOUT_DELTA(60);
        engine->timeouts[PneumoState_17] = TIMEOUT_DELTA(30);
        engine->delays[PneumoState_17] = TIMEOUT_DELTA(60);
    }
}

void pneumo_engine_destroy(struct PneumoEngine *engine) {
    if (0 != engine) {
        
    }
}

#define TIMEOUT_GE(engine) ( (engine)->timeout > (engine)->timeouts[(engine)->state] )
#define DELAY_GE(engine) ( (engine)->delay > (engine)->delays[(engine)->state] )

bool pneumo_engine_tick(struct PneumoEngine *engine) {
    bool ret = true;
    if (0 == engine){return false;}
    switch (engine->state) {
        case PneumoState_Init: {
            engine -> state = PneumoState_1;
            engine -> delay = 0;
            engine -> timeout =0;
        }
        case PneumoState_0: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_1;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_1: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] ) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_2;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_4;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_2: {
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_3;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_3: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_4;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_16;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_4: {
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_5;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_5: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_6;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_6: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_7;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_7: {
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_8;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_8: {
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_9;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_9: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_10;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_10: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_11;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_11: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_12;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_12: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_13;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_13: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_14;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_14: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_15;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_15: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_16;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_16: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y8].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_17;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_17: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 1;
            engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y3].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y4].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y5].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y6].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
                engine->cylinders[PNEUMO_CYLINDER_Y7].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)){
                    engine->state = PneumoState_0;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
            }
            else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y3].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y4].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y5].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y6].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y7].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y8].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }
        case PneumoState_FatalException:{
            ret = false;
            break;
        }
    }
    engine->timeout++;
    engine->delay++;
    return ret;
}
