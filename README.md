# NanoOS na Cardputer ADV

Prototyp na M5Stack Cardputer ADV (StampS3) zbudowany w PlatformIO/Arduino, sluzacy do testowania nowej architektury UI/NanoOS zanim trafi ona do wiekszego projektu.

## Co zawiera
- Srodowisko `cardputer-adv` (board `m5stack-stamps3`, lib `M5Cardputer`) opisane w `platformio.ini`.
- Rdzen oparty o `App` + `Router` z mala historia tras oraz `AppContext` ze wspoldzielonymi serwisami (nawigacja, input, ustawienia, UI).
- Ekrany dziedzicza po `BaseScreen`, renderuja sie przez `UiService`, a logike dziela na komponenty (`components/` + `ComponentList`).
- Minimalne ekrany Home/Settings do sprawdzenia przeplywu nawigacji i akcji.

## Jak uruchomic
1) Zainstaluj PlatformIO (CLI lub w VS Code).
2) Podlacz Cardputer ADV i zbuduj/wgraj: `pio run -t upload -e cardputer-adv`.
3) Podglad logow/serial: `pio device monitor -b 115200`.

## Struktura katalogow
- `src/core` — App, Router, KeyMapper, bazowe interfejsy i serwisy.
- `src/screens` — implementacje ekranow (Home, Settings).
- `src/components` — proste komponenty UI do ponownego uzycia.
- `include`, `lib`, `test` — standardowe katalogi PlatformIO na przyszle rozszerzenia.

## Status
To wczesny szkielet do weryfikacji architektury; ekran About/cale menu to stuby pod dalszy rozwoj. Priorytetem jest sprawdzenie przeplywow (nawigacja, input, rerender) na sprzecie Cardputer ADV.
