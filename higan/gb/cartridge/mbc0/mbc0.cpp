auto Cartridge::MBC0::mmio_read(uint16 addr) -> uint8 {
  if((addr & 0x8000) == 0x0000) {  //$0000-7fff
    return cartridge.rom_read(addr);
  }

  if((addr & 0xe000) == 0xa000) {  //$a000-bfff
    return cartridge.ram_read(addr & 0x1fff);
  }

  return 0x00;
}

auto Cartridge::MBC0::mmio_write(uint16 addr, uint8 data) -> void {
  if((addr & 0xe000) == 0xa000) {  //$a000-bfff
    cartridge.ram_write(addr & 0x1fff, data);
    return;
  }
}

auto Cartridge::MBC0::power() -> void {
}