# hpx-rs
Rust bindings to HPX, C++ Standard Library for Concurrency and
Parallelism.

## Rust version requirements
hpx-rs works with stable Rust.

## Version of hpx
Currently this library requires hpx-1.10(or newer). The user is required
to pre-install hpx and set the pkg-config to point to "*.pc" files of
hpx. The hpx-sys crate will then link to the hpx.

## Benchmarks
Rust benchmarks are generated using [Criterion](https://github.com/bheisler/criterion.rs)
and for Cpp we are using [google benchmark](https://github.com/google/benchmark).
To run rust benchmarks execute `cargo bench`. The report for rust
benchmarks will be available in `target/criterion/report/`.
To run cpp benchmarks you need to install [google benchmark](https://github.com/google/benchmark)
and then run 
```
clang++ -std=c++17 -O3 -DNDEBUG copy_benchmark.cpp \
    $(pkg-config --cflags --libs hpx_application) \
    -I/usr/local/include -I/usr/local/include/benchmark \
    -L/usr/local/lib -lhpx_iostreams -lbenchmark -lpthread \
    -DHPX_APPLICATION_NAME=copy_benchmark \
    -o copy_benchmark
```
 
