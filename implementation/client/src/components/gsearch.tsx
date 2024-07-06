"use client";
import React, { useEffect } from "react";

const GSearch = ({ iframeUrl }: { iframeUrl: string }) => {
  return (
    <div className="flex flex-col items-center size-full">
      <iframe
        src={`https://www.google.com/search?igu=1&q=${iframeUrl}`}
        className="size-full"
        onMouseEnter={(e) => {
          if (e.target instanceof HTMLAnchorElement) {
            e.preventDefault();
            console.log(e.target.href);
          }
        }}
      />
    </div>
  );
};

export default GSearch;
