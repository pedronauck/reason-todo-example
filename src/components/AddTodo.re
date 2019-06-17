open Utils;

module Styles = {
  open Css;

  let input =
    style([
      marginBottom(px(30)),
      padding2(~v=px(10), ~h=px(30)),
      border(px(0), none, black),
      backgroundColor(white),
      borderRadius(px(999)),
      boxShadow(~y=px(1), ~blur=px(3), rgba(0, 0, 0, 0.1)),
      fontSize(px(24)),
      fontWeight(`light),
      outlineStyle(`none),
    ]);
};

[@react.component]
let make = (~onSubmit) => {
  let (text, setText) = React.useState(() => "");

  let handleSubmit = ev => {
    ReactEvent.Form.preventDefault(ev);
    if (String.length(text) > 0) {
      onSubmit(text);
      setText(_ => "");
    };
  };

  let handleChange = ev => ev |> valFromEvent |> setText;

  <form onSubmit=handleSubmit>
    <input className=Styles.input value=text onChange=handleChange />
  </form>;
};
