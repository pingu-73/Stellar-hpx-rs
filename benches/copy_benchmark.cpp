#include <benchmark/benchmark.h>
#include <hpx/hpx_init.hpp>
#include <hpx/algorithm.hpp>
#include <vector>

static void BM_HPXCopy(benchmark::State& state) {
    std::vector<int> src(1000000, 1);
    std::vector<int> dest(1000000, 0);

    for (auto _ : state) {
        hpx::copy(hpx::execution::par, src.begin(), src.end(), dest.begin());
    }
}

BENCHMARK(BM_HPXCopy);

int hpx_main(int argc, char* argv[]) {
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return hpx::finalize();
}

int main(int argc, char* argv[]) {
    return hpx::init(hpx_main, argc, argv);
}
