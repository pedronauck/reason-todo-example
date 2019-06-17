open Utils;
open Theme;

type todo = {
  id: int,
  title: string,
  completed: bool,
};

module Check = {
  [@bs.module "react-feather/dist/icons/check-square"] [@react.component]
  external make: (~size: int, ~className: string) => React.element = "default";
};

module Styles = {
  open Css;
  let wrapper =
    style([
      display(flexBox),
      alignItems(center),
      padding2(~v=px(6), ~h=px(12)),
      hover([cursor(`pointer)]),
    ]);

  let text = completed =>
    style([
      color(Theme.Colors.grayDark),
      paddingLeft(px(10)),
      textDecoration(completed ? `lineThrough : `none),
    ]);

  let icon = completed =>
    style([
      SVG.stroke(completed ? Theme.Colors.success : Theme.Colors.grayLight),
    ]);
};

[@react.component]
let make = (~todo, ~onComplete) => {
  let handleClick = _ev => onComplete(todo.id);

  <div className=Styles.wrapper onClick=handleClick>
    <Check className={Styles.icon(todo.completed)} size=20 />
    <div className={Styles.text(todo.completed)}>
      {toString(todo.title)}
    </div>
  </div>;
};
