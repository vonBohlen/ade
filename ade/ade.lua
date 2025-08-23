function ade()
  warning("awm starting...");

  system_load("builtin/mouse.lua");
  system_load("builtin/keyboard.lua");

  initialize_desktop();
end

function initialize_desktop()
  local bg = load_image("bg.jpg", 2, 1280, 720);
  show_image(bg);


end
