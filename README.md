# cpuinfo
a simple program to show some info about your CPU

- [x] cross-platform (Win, Lin, Mac)
- [ ] supports only Intel CPUs (no ARM, sorry)
- [x] uses [libcpuid](https://github.com/anrieff/libcpuid) to get actual data
- [x] uses vcpkg and cmake for heavy-lifting
- [x] uses [Dependency injection](https://en.wikipedia.org/wiki/Dependency_injection) for testability
- [x] [this commit](https://github.com/Lex-2008/cpuinfo/commit/8e412f923846d83a2733eb3f6b9f083cb07b01f3) shows adding a new feature with a test

TODOs implemented on the [`next`](https://github.com/Lex-2008/cpuinfo/tree/next) branch:

- [x] cache vcpkg deps
- [x] switch vcpkg to Manifest mode (good for deps caching)
- [x] [this commit](https://github.com/Lex-2008/cpuinfo/commit/07f9b8c2a42c21e0f250f7a2c3f7a1f89fad6137) shows adding a new dependency (and also a feature requiring this dependency and also a new test for it)
- [x] archive artifacts (produced executables) for manual testing - although GitHub limits who can download them
- [x] test running them on "clean" machine
- [x] make release build (requested manually) - although to see the "Run workflow" button you must either switch "default branch" in repo settings to `next`, or merge `next` branch into `main`, ref [first note here](https://docs.github.com/en/actions/using-workflows/manually-running-a-workflow)

Nice-to-haves not implemented:

- [ ] Cross-platform build (failed attempt preserved in [this commit](https://github.com/Lex-2008/cpuinfo/blob/94a09eb325124b4918a07cecdc5b8b4babcce6e3/.github/workflows/cross.yml))
- [ ] move files into dirs: `src` for sources, `tests` for tests, `build` for build, etc
- [ ] add command line args to the program - what data to output, how to get cpu frequency, how to format output - also will add a new dependency
- [ ] make release build when tag is pushed
- [ ] push release artifacts to "releases" page on GitHub
