[%bs.raw {| require('./App.css') |}];

open TodoItem;
let initialTodos = [
  {id: 1, title: "Buy fruits", completed: false},
  {id: 2, title: "Give some money", completed: true},
];

module Styles = {
  open Css;

  let wrapper =
    style([
      display(flexBox),
      flexDirection(column),
      justifyContent(center),
      width(px(500)),
      height(vh(100.)),
      paddingLeft(px(100)),
    ]);
};

[@react.component]
let make = () => {
  let (todos, setTodos) = React.useState(() => initialTodos);

  let handleAddTodo = text => {
    let nextId = (todos |> List.rev |> List.hd).id + 1;
    let newTodo = {id: nextId, title: text, completed: false};

    setTodos(List.append(_, [newTodo]));
  };

  let handleCompleteTodo = id => {
    let findAndComplete =
      List.map(todo =>
        todo.id == id ? {...todo, completed: !todo.completed} : todo
      );

    setTodos(findAndComplete);
  };

  <div className=Styles.wrapper>
    <AddTodo onSubmit=handleAddTodo />
    <Todos todos onComplete=handleCompleteTodo />
  </div>;
};
