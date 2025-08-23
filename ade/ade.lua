 function ade()
  warning("awm starting...\n");

  system_load("builtin/mouse.lua");
  system_load("builtin/keyboard.lua");
  system_load("src/cursor.lua");

  initialize_desktop();
  cursor.init_cursor();
end

function initialize_desktop()
  local bg = load_image("bg.jpg", 2, 1280, 720);
  show_image(bg);

  local pb = load_image("pb.png", 3, 52, 320);
  show_image(pb);


end
