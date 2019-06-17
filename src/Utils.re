let toString = ReasonReact.string;
let toArr = list => list |> Array.of_list |> ReasonReact.array;
let valFromEvent = ev => ReactEvent.Form.target(ev)##value;
