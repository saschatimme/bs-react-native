module type ScrollViewComponent = {
  type point = {x: float, y: float};
  let scrollTo: ReactRe.reactRef => x::int => y::int => animated::bool => unit;
  let scrollToEnd: ReactRe.reactRef => animated::bool => unit;
  let createElement:
    accessibleLeft::ReactRe.reactElement? =>
    accessible::bool? =>
    hitSlop::TypesRN.insets? =>
    onAccessibilityTap::(unit => unit)? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onMagicTap::(unit => unit)? =>
    responderHandlers::Props.touchResponderHandlers? =>
    pointerEvents::[ | `auto | `none | `boxNone | `boxOnly]? =>
    removeClippedSubviews::bool? =>
    style::StyleRe.t? =>
    testID::string? =>
    accessibilityComponentType::
      [ | `none | `button | `radiobutton_checked | `radiobutton_unchecked]? =>
    accessibilityLiveRegion::[ | `none | `polite | `assertive]? =>
    collapsable::bool? =>
    importantForAccessibility::[ | `auto | `yes | `no | `noHideDescendants]? =>
    needsOffscreenAlphaCompositing::bool? =>
    renderToHardwareTextureAndroid::bool? =>
    accessibilityTraits::
      list [
        | `none
        | `button
        | `link
        | `header
        | `search
        | `image
        | `selected
        | `plays
        | `key
        | `text
        | `summary
        | `disabled
        | `frequentUpdates
        | `startsMedia
        | `adjustable
        | `allowsDirectInteraction
        | `pageTurn
      ]? =>
    accessibilityViewIsModal::bool? =>
    shouldRasterizeIOS::bool? =>
    contentContainerStyle::StyleRe.t? =>
    horizontal::bool? =>
    keyboardDismissMode::[ | `none | `interactive | `onDrag]? =>
    keyboardShouldPersistTaps::[ | `always | `never | `handled]? =>
    onContentSizeChange::((float, float) => unit)? =>
    onScroll::(RNEvent.NativeEvent.t => unit)? =>
    pagingEnabled::bool? =>
    refreshControl::ReactRe.reactElement? =>
    scrollEnabled::bool? =>
    showsHorizontalScrollIndicator::bool? =>
    showsVerticalScrollIndicator::bool? =>
    stickyHeaderIndices::list int? =>
    overScrollMode::[ | `always | `never | `auto]? =>
    scrollPerfTag::string? =>
    alwaysBounceHorizontal::bool? =>
    alwaysBounceVertical::bool? =>
    automaticallyAdjustContentInsets::bool? =>
    bounces::bool? =>
    canCancelContentTouches::bool? =>
    centerContent::bool? =>
    contentInset::TypesRN.insets? =>
    contentOffset::point? =>
    decelerationRate::[ | `fast | `normal]? =>
    directionalLockEnabled::bool? =>
    indicatorStyle::[ | `default | `black | `white]? =>
    maximumZoomScale::float? =>
    mimimumZoomScale::float? =>
    onScrollAnimationEnd::(unit => unit)? =>
    scrollEventThrottle::int? =>
    scrollIndicatorInsets::TypesRN.insets? =>
    scrollsToTop::bool? =>
    snapToAlignment::[ | `center | `start | `end_]? =>
    zoomScale::float? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

module CreateComponent (Impl: ViewRe.Impl) :ScrollViewComponent => {
  type point = {x: float, y: float};
  external _scrollTo : ReactRe.reactRef => Js.t {. x : int, y : int, animated : Js.boolean} => unit =
    "scrollTo" [@@bs.send];
  external _scrollToEnd : ReactRe.reactRef => Js.t {. animated : Js.boolean} => unit =
    "scrollToEnd" [@@bs.send];
  let scrollTo ref ::x ::y ::animated =>
    _scrollTo ref {"x": x, "y": y, "animated": Js.Boolean.to_js_boolean animated};
  let scrollToEnd ref ::animated =>
    _scrollToEnd ref {"animated": Js.Boolean.to_js_boolean animated};
  let createElement
      ::accessibleLeft=?
      ::accessible=?
      ::hitSlop=?
      ::onAccessibilityTap=?
      ::onLayout=?
      ::onMagicTap=?
      ::responderHandlers=?
      ::pointerEvents=?
      ::removeClippedSubviews=?
      ::style=?
      ::testID=?
      ::accessibilityComponentType=?
      ::accessibilityLiveRegion=?
      ::collapsable=?
      ::importantForAccessibility=?
      ::needsOffscreenAlphaCompositing=?
      ::renderToHardwareTextureAndroid=?
      ::accessibilityTraits=?
      ::accessibilityViewIsModal=?
      ::shouldRasterizeIOS=?
      ::contentContainerStyle=?
      ::horizontal=?
      ::keyboardDismissMode=?
      ::keyboardShouldPersistTaps=?
      ::onContentSizeChange=?
      ::onScroll=?
      ::pagingEnabled=?
      ::refreshControl=?
      ::scrollEnabled=?
      ::showsHorizontalScrollIndicator=?
      ::showsVerticalScrollIndicator=?
      ::stickyHeaderIndices=?
      ::overScrollMode=?
      ::scrollPerfTag=?
      ::alwaysBounceHorizontal=?
      ::alwaysBounceVertical=?
      ::automaticallyAdjustContentInsets=?
      ::bounces=?
      ::canCancelContentTouches=?
      ::centerContent=?
      ::contentInset=?
      ::contentOffset=?
      ::decelerationRate=?
      ::directionalLockEnabled=?
      ::indicatorStyle=?
      ::maximumZoomScale=?
      ::mimimumZoomScale=?
      ::onScrollAnimationEnd=?
      ::scrollEventThrottle=?
      ::scrollIndicatorInsets=?
      ::scrollsToTop=?
      ::snapToAlignment=?
      ::zoomScale=? =>
    ReactRe.wrapPropsShamelessly
      Impl.view
      (
        Props.extendView
          Js.Undefined.(
            {
              "contentContainerStyle": from_opt contentContainerStyle,
              "horizontal": from_opt (UtilsRN.optBoolToOptJsBoolean horizontal),
              "keyboardDismissMode":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun x =>
                        switch x {
                        | `interactive => "interactive"
                        | `none => "none"
                        | `onDrag => "on-drag"
                        }
                    )
                    keyboardDismissMode
                ),
              "keyboardShouldPersistTaps":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun x =>
                        switch x {
                        | `always => "always"
                        | `never => "never"
                        | `handled => "handled"
                        }
                    )
                    keyboardShouldPersistTaps
                ),
              "onContentSizeChange": from_opt onContentSizeChange,
              "onScroll": from_opt onScroll,
              "pagingEnabled": from_opt (UtilsRN.optBoolToOptJsBoolean pagingEnabled),
              "refreshControl": from_opt refreshControl,
              "scrollEnabled": from_opt (UtilsRN.optBoolToOptJsBoolean scrollEnabled),
              "showsHorizontalScrollIndicator":
                from_opt (UtilsRN.optBoolToOptJsBoolean showsHorizontalScrollIndicator),
              "showsVerticalScrollIndicator":
                from_opt (UtilsRN.optBoolToOptJsBoolean showsVerticalScrollIndicator),
              "stickyHeaderIndices": from_opt (UtilsRN.option_map Array.of_list stickyHeaderIndices),
              "overScrollMode":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun x =>
                        switch x {
                        | `always => "always"
                        | `never => "never"
                        | `auto => "auto"
                        }
                    )
                    overScrollMode
                ),
              "scrollPerfTag": from_opt scrollPerfTag,
              "alwaysBounceHorizontal":
                from_opt (UtilsRN.optBoolToOptJsBoolean alwaysBounceHorizontal),
              "alwaysBounceVertical": from_opt (UtilsRN.optBoolToOptJsBoolean alwaysBounceVertical),
              "automaticallyAdjustContentInsets":
                from_opt (UtilsRN.optBoolToOptJsBoolean automaticallyAdjustContentInsets),
              "bounces": from_opt (UtilsRN.optBoolToOptJsBoolean bounces),
              "canCancelContentTouches":
                from_opt (UtilsRN.optBoolToOptJsBoolean canCancelContentTouches),
              "centerContent": from_opt (UtilsRN.optBoolToOptJsBoolean centerContent),
              "contentInset": from_opt contentInset,
              "contentOffset":
                from_opt (UtilsRN.option_map (fun {x, y} => {"x": x, "y": y}) contentOffset),
              "decelerationRate":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun x =>
                        switch x {
                        | `fast => "fast"
                        | `normal => "normal"
                        }
                    )
                    decelerationRate
                ),
              "directionalLockEnabled":
                from_opt (UtilsRN.optBoolToOptJsBoolean directionalLockEnabled),
              "indicatorStyle":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun x =>
                        switch x {
                        | `default => "default"
                        | `black => "black"
                        | `white => "white"
                        }
                    )
                    indicatorStyle
                ),
              "maximumZoomScale": from_opt maximumZoomScale,
              "mimimumZoomScale": from_opt mimimumZoomScale,
              "onScrollAnimationEnd": from_opt onScrollAnimationEnd,
              "scrollEventThrottle": from_opt scrollEventThrottle,
              "scrollIndicatorInsets": from_opt scrollIndicatorInsets,
              "scrollsToTop": from_opt (UtilsRN.optBoolToOptJsBoolean scrollsToTop),
              "snapToAlignment":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun x =>
                        switch x {
                        | `center => "center"
                        | `start => "start"
                        | `end_ => "end"
                        }
                    )
                    snapToAlignment
                ),
              "zoomScale": from_opt zoomScale
            }
          )
          ::accessibleLeft
          ::accessible
          ::hitSlop
          ::onAccessibilityTap
          ::onLayout
          ::onMagicTap
          ::responderHandlers
          ::pointerEvents
          ::removeClippedSubviews
          ::style
          ::testID
          ::accessibilityComponentType
          ::accessibilityLiveRegion
          ::collapsable
          ::importantForAccessibility
          ::needsOffscreenAlphaCompositing
          ::renderToHardwareTextureAndroid
          ::accessibilityTraits
          ::accessibilityViewIsModal
          ::shouldRasterizeIOS
      );
};

module ScrollView =
  CreateComponent {
    external view : ReactRe.reactClass = "ScrollView" [@@bs.module "react-native"];
  };
