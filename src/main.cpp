// main.cpp — entry point. Wires config and subsystems together.

#include "copilottokenabuse/settings.h"
#include "copilottokenabuse/pool.h"
#include "copilottokenabuse/rotate.h"
#include "copilottokenabuse/proxy.h"
#include "copilottokenabuse/cli.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    copilottokenabuse::Settings settings = copilottokenabuse::Settings::load_default();
    copilottokenabuse::Pool pool(settings.store_path);
    copilottokenabuse::Rotate rotate(settings.store_path);
    copilottokenabuse::Proxy proxy(settings.store_path);
    copilottokenabuse::Cli cli(settings.store_path);
    std::fprintf(stderr, "[copilot-token-abuse] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
