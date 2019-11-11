type importable('a) = {
  .
  "__esModule": bool,
  "$$default": bool,
  [@bs.meth] "propertyIsEnumerable": string => bool,
};

[@bs.val] external import: string => Js.Promise.t(importable('a)) = "import";

[@bs.module "react"]
external lazy_: (unit => Js.Promise.t(importable('a))) => 'a = "lazy";

let load = moduleName => lazy_(() => import({j|./$moduleName.bs.js|j}));