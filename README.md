# flatpak builder setup

```
flatpak install -y flathub org.flatpak.Builder
flatpak remote-add --if-not-exists --user flathub https://dl.flathub.org/repo/flathub.flatpakrepo
```

# Build

```
flatpak run org.flatpak.Builder  -v --force-clean --user --install-deps-from=flathub --repo=repo --install builddir bug.libremidi.bugremidi.yml
```

# Run

```
 flatpak run bug.libremidi.bugremidi
```
